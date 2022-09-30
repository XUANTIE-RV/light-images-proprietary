echo verify golden case script

if [ ! -d "../../../../test/golden/engine" ]; then
    echo no golden data in /test/golden/engine
    exit 0
fi

./isp_test 2|tee debug.txt

