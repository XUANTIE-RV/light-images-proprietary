#!/bin/sh -x
#
# below repo images have proprietary, need Yocto to copy out:
# npu_ax3386
# fce_thead
# thead_ddr_pmu
#
# vpu_vc8000d, vpu_vc8000e
# vpu_openmax_il
#
# isp_isp8000l
#
# gpu_bxm_4_64
#
# libgal-viv
# libcsi-g2d
#

MACHINE=light-fm-bsp-v1.1.0
 
export YOCTO_DIR=`pwd`
if [ ! -d "yocto_rootfs_proprietary" ]
then
	mkdir yocto_rootfs_proprietary
fi
export LIGHT_SDK_PROPRIETARY_YOCTO_DIR=$YOCTO_DIR/yocto_rootfs_proprietary
export LOCAL_ROOTFS_DIR=$YOCTO_DIR/thead-build/light-fm/tmp-glibc/work/$MACHINE-oe-linux/light-fm-image/1.0-r0/rootfs
export BUILD_DIR=$YOCTO_DIR/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux

# start to copy images:

# npu_ax3386
NPU_SRC=$BUILD_DIR/npu-ax3386/1.0-r0/git
cp -r $NPU_SRC/output/rootfs/bsp/npu $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/

# fce_thead
FCE_SRC=$BUILD_DIR/thead-fce/1.0-r0/git
cp -r $FCE_SRC/output/rootfs/bsp/fce $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/

# thead_ddr_pmu
DDR_PMU=$BUILD_DIR/thead-ddr-pmu/1.0-r0/git
cp -r $DDR_PMU/output/rootfs/bsp/ddr-pmu $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/

# vpu_openmax_il
VPU_OPENMAX_IL=$BUILD_DIR/vpu-omxil/1.0-r0/sysroot-destdir
cp -r $VPU_OPENMAX_IL $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/vpu-omxil

# isp_isp8000l
ISP8000L=$BUILD_DIR/isp-isp8000l/1.0-r0/git
cp -r $ISP8000L/output/rootfs/bsp $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l
cp -r $ISP8000L/csi_camera_hal_inc/include/hal $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l
cp -r $ISP8000L/csi_hal/include/common/csi_camera_dev_api.h $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/hal
cp -r $ISP8000L/vi_mem/output/*.so $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/isp/lib
cp -r $ISP8000L/build $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l
cp -r $ISP8000L/dist $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l
cp -r $ISP8000L/units/isi/drv/GC5035/source/csi_cfg.sh $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l
if [ ! -d "$LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/include" ]
then
	mkdir $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/include
fi
rm -rf $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/isp/test/ISP8000L_V2008
rm -rf $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/dw200/test/case
rm -rf $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/isp_ry/test/ISP8000_V2009
rm -rf $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/build/riscv64-unknown-linux-gnu/debug/appshell/generated/debug/bin/ISP8000L_V2008
rm -rf $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/isp-isp8000l/build/riscv64-unknown-linux-gnu/debug/appshell/ISP8000L_V2008

# gpu_bxm_4_64
GPU_SRC=$BUILD_DIR/gpu-bxm-4-64/1.0-r0/git
cp -r $GPU_SRC/../image $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/gpu_bxm_4_64

# libgal-viv
G2D_SRC=$BUILD_DIR/libgal-viv/6.4.6.9-r0/git
cp -r $G2D_SRC/build/sdk $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/libgal-viv-sdk

# libcsi-g2d
G2D_HAL_SRC=$BUILD_DIR/libcsi-g2d/1.0.0-r0/git
cp -r $G2D_HAL_SRC/build $LIGHT_SDK_PROPRIETARY_YOCTO_DIR/libcsi-g2d-sdk
