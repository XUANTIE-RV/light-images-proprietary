#!/usr/bin/env ruby

begin
  puts <<USAGE_DOCUMENT
Usage: m_read.rb address
USAGE_DOCUMENT
  exit
end unless ARGV.length >= 1

#p ARGV
address = ARGV[0]

require 'mmio'
include MemoryMappedIO

require 'bindata'


address_hex = address.to_i(16)
reg_base_addr = eval(ENV["gpu_regbase"])
readdata = mread( reg_base_addr + address_hex, 'w')
puts "0x%x"%readdata
