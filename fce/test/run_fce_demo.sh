#!/bin/sh
BASE_PATH=./
TEST_PATH=${BASE_PATH}test
RES_PATH=${TEST_PATH}/resource
OUT_PATH=${TEST_PATH}/out

INPUT=${RES_PATH}/input/vector_float_norm.txt
FEATURE_LIB=${RES_PATH}/featurelib/anti-incre_softmax/featurelib_int8_demo.txt

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
  ${TEST_PATH}/fce_demo ${INPUT} ${FEATURE_LIB}
else
  ${TEST_PATH}/fce_demo ${INPUT} ${FEATURE_LIB} > test.log
fi
