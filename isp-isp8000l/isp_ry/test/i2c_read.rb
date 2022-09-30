#!/usr/bin/env ruby

begin
  puts <<USAGE_DOCUMENT
Usage: i2c_read.rb bus_id slave_addr address
USAGE_DOCUMENT
  exit
end unless ARGV.length >= 3

#p ARGV
bus_id = ARGV[0]
slave_addr = ARGV[1]
address = ARGV[2]

load "s2c_i2c.rb"

bus_id_hex = bus_id.to_i(16)
slave_addr_hex = slave_addr.to_i(16)
address_hex = address.to_i(16)

readdata = csi_i2c_read(bus_id_hex, slave_addr_hex, address_hex)
puts "%d"%readdata
