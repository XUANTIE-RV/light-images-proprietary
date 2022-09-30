#!/usr/bin/env ruby

require 'fileutils'

begin
  puts <<USAGE_DOCUMENT
Usage: s2c_i2c.rb
USAGE_DOCUMENT
  exit
end unless ARGV.length >= 0

load "/root/sdk/S2C/bin/common/i2c_channel.rb"
include MemoryMappedIO

#reg_bar = 0xde30_0000
#reg_bar = 0xf000_0000
reg_bar = eval(ENV["gpu_regbase"]) | 0x30_0000

unless mread(reg_bar + 0x00_8000, 'w') == 0x8765_4321 || mread(reg_bar + 0x00_8000, 'w') == 0x0fed_cba9
  puts "ERROR: Device axilite_agent is not found."
  exit
end

################################################################################
def time_of(sec)
  min, second = sec.divmod(60)
  hrs, minute = min.divmod(60)
  day, hour   = hrs.divmod(24)
  ((day == 0)? "": "#{day} day%s"%((day>1)? "s":"")) +
  ((hour == 0)? "": "#{hour} hour%s"%((hour>1)? "s":"")) +
  ((minute == 0)? "": "#{minute} minute%s"%((minute>1)? "s":"")) +
  "#{second} second%s"%((second>1)? "s":"")
end

class Array

  def ask_one_item(prompt="Please select one item:", ins=$stdin, outs=$stdout, errs=$stderr)
    return self.pop if(self.size == 1)
    loop do
      outs.puts prompt
      self.inject(1) { |item_idx, e|    outs.puts "  (#{item_idx}) #{e}"; item_idx=item_idx+1}
      outs.print "Choose(Enter only to exit): "
      s = ins.gets
      exit if (s == nil)
      s.chomp!
      exit if (s == "")
      if (1 .. self.size) === s.to_i
        return self[s.to_i - 1]
      end
      errs.puts "Please input the valid item number."
    end
  end

end

################################################################################

#i2c_program_file = ARGV[0]
#do_hw_reset = false
#
#ARGV[1..-1].each do |option_item|
#  do_hw_reset = true if(option_item =~ /do_hw_reset/i)
#end
#
# if do_hw_reset
#  rsd_ctrl = mread(0x43c1_0074, 'w')
#  rsd_ctrl &= ~0x10
#  mwrite(0x43c1_0074, 'w', rsd_ctrl)
#  sleep(1.0)
#  rsd_ctrl |= 0x10
#  mwrite(0x43c1_0074, 'w', rsd_ctrl)
#  sleep(1.0)
# end


def csi_i2c_read( bus_id, slave_addr, addr)
  reg_bar = eval(ENV["gpu_regbase"]) | 0x30_0000
  if(bus_id == 0)
    i2c_access_0 = I2C_channel.new(:extra_delay=>0, :reg_base=>reg_bar, :gpio_reg_addr=>(reg_bar|0x80f0|(0<<2)))
    $csi_i2c_access = i2c_access_0
  else
    i2c_access_1 = I2C_channel.new(:extra_delay=>0, :reg_base=>reg_bar, :gpio_reg_addr=>(reg_bar|0x80f0|(1<<2)))
    $csi_i2c_access = i2c_access_1
  end
  $csi_i2c_access.da_ra_rdata(slave_addr, [addr].pack("S*").unpack("CC").reverse)
end

def csi_i2c_write( bus_id, slave_addr, addr, *data)
  reg_bar = eval(ENV["gpu_regbase"]) | 0x30_0000
  if(bus_id == 0)
    i2c_access_0 = I2C_channel.new(:extra_delay=>0, :reg_base=>reg_bar, :gpio_reg_addr=>(reg_bar|0x80f0|(0<<2)))
    $csi_i2c_access = i2c_access_0
  else
    i2c_access_1 = I2C_channel.new(:extra_delay=>0, :reg_base=>reg_bar, :gpio_reg_addr=>(reg_bar|0x80f0|(1<<2)))
    $csi_i2c_access = i2c_access_1
  end

  $csi_i2c_access.da_ra_wdata(slave_addr, [addr].pack("S*").unpack("CC").reverse, *data)
end


