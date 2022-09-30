#!/bin/sh
BASE_PATH=./
TEST_PATH=${BASE_PATH}test
RES_PATH=${TEST_PATH}/resource/
OUT_PATH=${TEST_PATH}/out

#export LD_LIBRARY_PATH=${BASE_PATH}/lib/:$LD_LIBRARY_PATH

VERBOSE=0
while getopts ":v:" opt
do
  case $opt in
    v)
    VERBOSE=$OPTARG
    ;;
    ?)
    echo "unsupport parameter!!!"
    exit 1;;
  esac
done

rm -rf ${OUT_PATH}; mkdir -p ${OUT_PATH}

if [ "${VERBOSE}" == "1" ]; then
  ${TEST_PATH}/fce_testcase
else
  ${TEST_PATH}/fce_testcase > test.log
fi
