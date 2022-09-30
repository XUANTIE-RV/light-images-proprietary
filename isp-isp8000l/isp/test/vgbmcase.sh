echo verify baremetal golden case script

if [ ! -d "../../../test/golden/data" ]; then
    echo no golden data in test/golden/data
    exit 0
fi

if [ ! -d "case" ]; then
    echo copying sw case data to folder
    mkdir case
    cp ../../../test/case . -R
    mv case/global_settings_fpga.txt case/global_settings.txt
fi

if [ -f "case/bare_metal/data" ]; then
    echo remove old link
    rm case/bare_metal/data
fi

ln -s ../../../../../test/golden/data case/bare_metal/data

./isp_test 1|tee debug.txt

