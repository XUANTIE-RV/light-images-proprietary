// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright(C) 2021 Alibaba Communications Inc.
 * Author: David Li <liyong.li@alibaba-inc.com>
 */

#ifndef _FCE_UAPI_H_
#define _FCE_UAPI_H_
#include "fce_cfg.h"

#if defined(__KERNEL__)
#include <linux/ioctl.h>
#include <linux/types.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#include <inttypes.h>
#else
#error unsupported build
#endif

#if defined(__cplusplus)
extern "C" {
#endif


struct fce_ioctl_data {
	struct fce_cfg cfg; // fce attribute
	unsigned int chn_id; // the channel id for netlink_unicast
	unsigned int result_cnt; // the output count
	struct target_vector target_vect[TARGET_VECTOR_CNT]; // input features
	struct top_result top_buf[TOPREG_CNT]; // output vector
};

struct fce_uapi_state {
	unsigned int basenum;
	unsigned int isr_cnt;
};

#define FCE_IOC_MAGIC  'f'
#define FCE_IOC_MAX_NR  13

#define FCE_QUERY_STATE		_IOR(FCE_IOC_MAGIC,  0, struct fce_uapi_state)
#define FCE_QUERY_ISR_CNT	_IOR(FCE_IOC_MAGIC,  1, struct fce_uapi_state)
#define FCE_QUERY_RESULT_CNT	_IOR(FCE_IOC_MAGIC,  2, struct fce_uapi_state)
#define FCE_SET_RESULT_CNT	_IOR(FCE_IOC_MAGIC,  3, struct fce_uapi_state)
#define FCE_SET_ATTR		_IOR(FCE_IOC_MAGIC,  4, struct fce_uapi_state)
#define FCE_GET_ATTR		_IOR(FCE_IOC_MAGIC,  5, struct fce_uapi_state)
#define FCE_SET_CHN_ID		_IOR(FCE_IOC_MAGIC,  6, struct fce_uapi_state)
#define FCE_START		_IOR(FCE_IOC_MAGIC,  7, struct fce_uapi_state)
#define FCE_STOP		_IOR(FCE_IOC_MAGIC,  8, struct fce_uapi_state)
#define FCE_GET_RESULT		_IOR(FCE_IOC_MAGIC,  9, struct fce_uapi_state)
#define FCE_SUSPEND		_IOR(FCE_IOC_MAGIC,  10, struct fce_uapi_state)
#define FCE_RESUME		_IOR(FCE_IOC_MAGIC,  11, struct fce_uapi_state)
#define FEATURE_LIB_CREATE	_IOR(FCE_IOC_MAGIC,  12, struct fce_uapi_state)
#define FEATURE_LIB_FREE	_IOR(FCE_IOC_MAGIC,  13, struct fce_uapi_state)


#if defined(__cplusplus)
}
#endif

#endif /* _FCE_UAPI_H_ */
