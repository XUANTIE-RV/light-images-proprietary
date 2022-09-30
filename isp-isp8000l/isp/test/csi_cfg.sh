dev_pwd="/sys/devices/platform/soc/ffe4010000.csi/" 
memtool mw 0xffe4000040 0
memtool mw 0xffe4000044 0
echo 438 > $dev_pwd"dphy_freq"
echo 12 > $dev_pwd"len_config"
echo 2 > $dev_pwd"n_lanes"
#2c is raw12, 2b is raw10
#echo 0x2b > $dev_pwd"data_type"
echo 0x2b > $dev_pwd"data_type"

echo 0x00 > $dev_pwd"hsa"
echo 0x00 > $dev_pwd"hbp"
echo 0x00 > $dev_pwd"hsd"

echo 0x40 > $dev_pwd"ipi2_hsa"
echo 0x300 > $dev_pwd"ipi2_hbp"
echo 0x100 > $dev_pwd"ipi2_hsd"

echo 0x20 > $dev_pwd"ipi3_hsa"
echo 0x400 > $dev_pwd"ipi3_hbp"
echo 0x300 > $dev_pwd"ipi3_hsd"

echo 0 > $dev_pwd"ipi_timings_mode"
echo 1 > $dev_pwd"ipi_color_mode"
#for ov5693 640*480
#echo 36 > $dev_pwd"dw_dphy_g118_settle"
#for ov2775 1920*1080
echo 0 > $dev_pwd"virtual_channel"
#echo 1 > $dev_pwd"ipi2_virtual_channel"
#echo 2 > $dev_pwd"ipi3_virtual_channel"
echo 1 > $dev_pwd"ipi_enable_mask"
echo "*********************************************"

echo -n "dphy_freq: "
cat $dev_pwd"dphy_freq"
echo -n "len_config: "
cat $dev_pwd"len_config"
echo -n "n_lanes: "
cat $dev_pwd"n_lanes"
echo -n "data_type: "
cat $dev_pwd"data_type"

echo -n "hsa: "
cat $dev_pwd"hsa"
echo -n "hbp: "
cat $dev_pwd"hbp"
echo -n "hsd: "
cat $dev_pwd"hsd"

echo -n "ipi2_hsa: "
cat $dev_pwd"ipi2_hsa"
echo -n "ipi2_hbp: "
cat $dev_pwd"ipi2_hbp"
echo -n "ipi2_hsd: "
cat $dev_pwd"ipi2_hsd"

echo -n "ipi3_hsa: "
cat $dev_pwd"ipi3_hsa"
echo -n "ipi3_hbp: "
cat $dev_pwd"ipi3_hbp"
echo -n "ipi3_hsd: "
cat $dev_pwd"ipi3_hsd"

cat $dev_pwd"ipi_timings_mode"
cat $dev_pwd"ipi_color_mode"
sleep 1

memtool mw 0xffe4040184 0x122
memtool mw 0xffe4010044 1
echo 1 > $dev_pwd"csi_power"
memtool md -l 0xffe401004c+1
sleep 1
