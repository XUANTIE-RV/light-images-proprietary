// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright(C) 2021 Alibaba Communications Inc.
 * Author: David Li <liyong.li@alibaba-inc.com>
 */

#ifndef _FCE_HAL_H_
#define _FCE_HAL_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "fce_cfg.h"

enum FCE_EVENT {
    FCE_EVENT_COMPLETE = 0,
    FCE_EVENT_PAUSE,
    FCE_EVENT_BUSERR,
    FCE_EVENT_TIMEOUT,
    FCE_EVENT_UNDEFMSG,
    FCE_EVENT_SOCKERR,
    FCE_EVENT_OTHER
};

typedef void *csi_fce_handle_t;
typedef void *csi_fce_sock_handle_t;

int csi_fce_open(csi_fce_handle_t *fce_handle, char *name);
int csi_fce_close(csi_fce_handle_t fce_handle);
int csi_fce_query_result_cnt(csi_fce_handle_t fce_handle, unsigned int *cnt);
int csi_fce_set_result_cnt(csi_fce_handle_t fce_handle, unsigned int *cnt);
int csi_fce_set_attr(csi_fce_handle_t fce_handle, struct fce_cfg *cfg);
int csi_fce_get_attr(csi_fce_handle_t fce_handle, struct fce_cfg *cfg);
int csi_fce_do_compare(csi_fce_handle_t fce_handle, struct target_vector *target_vect);
int csi_fce_get_result(csi_fce_handle_t fce_handle, struct top_result *top_buf);
int csi_fce_suspend(csi_fce_handle_t fce_handle);
int csi_fce_resume(csi_fce_handle_t fce_handle);

unsigned long csi_fce_create_featurelib(csi_fce_handle_t fce_handle, unsigned int size);
int csi_fce_release_featurelib(csi_fce_handle_t fce_handle, unsigned long offset);

int csi_fce_config_init(struct fce_cfg *cfg);
int csi_fce_check_result(struct top_result *res1, struct top_result *res2);

int csi_fce_init_sock(csi_fce_sock_handle_t *sock_handle, unsigned long timeout_ms);
int csi_fce_release_sock(csi_fce_sock_handle_t sock_handle);
enum FCE_EVENT csi_fce_waitevent(csi_fce_sock_handle_t sock_handle);

#ifdef __cplusplus
}
#endif

#endif // #ifndef _FCE_HAL_H_