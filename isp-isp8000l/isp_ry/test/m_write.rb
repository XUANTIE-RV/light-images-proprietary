#!/usr/bin/env ruby

begin
  puts <<USAGE_DOCUMENT
Usage: m_write.rb address data
USAGE_DOCUMENT
  exit
end unless ARGV.length >= 2

#p ARGV
address = ARGV[0]
data = ARGV[1]

require 'mmio'
include MemoryMappedIO

require 'bindata'


address_hex = address.to_i(16)
data_hex = data.to_i(16)

reg_base_addr = eval(ENV["gpu_regbase"])

mwrite( reg_base_addr + address_hex, "w", data_hex)
readdata = mread( reg_base_addr + address_hex, 'w')
puts "readback: 0x%x"%readdata
