#!/usr/bin/env ruby

begin
  puts <<USAGE_DOCUMENT
Usage: i2c_write.rb bus_id slave_addr address data

USAGE_DOCUMENT
  exit
end unless ARGV.length >= 4

#p ARGV
bus_id = ARGV[0]
slave_addr = ARGV[1]
address = ARGV[2]
data = ARGV[3]

load "s2c_i2c.rb"

if(true)
bus_id_hex = bus_id.to_i(16)
slave_addr_hex = slave_addr.to_i(16)
address_hex = address.to_i(16)
data_hex = data.to_i(16)

#puts "write bus: 0x%x, slaveaddr:0x%x, address: 0x%x, data:%x"%[bus_id_hex, slave_addr_hex, address_hex, data_hex]
csi_i2c_write(bus_id_hex, slave_addr_hex, address_hex, data_hex)

puts "0"
#readback verification
#readdata = csi_i2c_read(bus_id_hex, slave_addr_hex, address_hex)
##puts "read data back:%x"%readdata
#if(readdata == data_hex)
#    puts "0"
#else
#    puts "1"
#end

end
#puts "1"
