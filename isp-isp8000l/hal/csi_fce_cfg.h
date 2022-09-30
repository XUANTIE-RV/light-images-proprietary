// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright(C) 2021 Alibaba Communications Inc.
 * Author: David Li <liyong.li@alibaba-inc.com>
 */

#ifndef FCE_CFG_H
#define FCE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#define MAX_BASE_NUM 1000000
#define TOPREG_CNT 8
#define TARGET_VECTOR_CNT 64
#define PREPRO_VECTOR_CNT 64
#define BITS_PER_BYTE 8

enum FCE_BASE_NUM {
	BASENUM_1 = 0,
	BASENUM_10,
	BASENUM_1w,
	BASENUM_5w,
	BASENUM_10w,
	BASENUM_20w,
	BASENUM_50w,
	BASENUM_100w,
	BASENUM_MAX = BASENUM_100w,
};

enum FCE_DIMENSION {
	DIM_128 = 0,
	DIM_160,
	DIM_192,
	DIM_224,
	DIM_256,
	DIM_MAX = DIM_256,
};

enum FCE_INT_WIDTH {
	INT_WIDTH_8 = 0,
	INT_WIDTH_4,
	INT_WIDTH_MAX = INT_WIDTH_4,
};

enum FCE_SIGN_SEL {
	UNSIGN = 0,
	SIGN,
	SIGSEL_MAX = SIGN,
};

struct target_vector {
	int value;
};

struct prepro_vector {
	int value;
};

enum FCE_ENDIAN_SEL {
	FCE_LIT_ENDIAN = 0,
	FCE_BIG_ENDIAN,
	FCE_ENDIAN_MAX = FCE_BIG_ENDIAN,
};

struct fce_cfg {
	unsigned int base_num;	// feature num in library, < MAX_BASE_NUM
	// comparasion start address in feature library buffer, default is 0
	unsigned long offset_base;
	unsigned long saddr;	// fill in kernel driver
	enum FCE_DIMENSION dim;	// dimension
	enum FCE_INT_WIDTH width;
	enum FCE_SIGN_SEL sigsel;	// sign or unsign
	unsigned int readnum;	// number of target vector, unit byte
	// data endian format of feature library
	enum FCE_ENDIAN_SEL base_endian;
	// data endian format of target feature vector for comparasion
	enum FCE_ENDIAN_SEL target_endian;
	// data endian format of xor operation on the feature library
	enum FCE_ENDIAN_SEL prepro_endian;
	struct prepro_vector prepro_vect[PREPRO_VECTOR_CNT]; // xor vector
};

struct top_result {
	int match_value;
	unsigned int match_index;
};

#ifdef __cplusplus
}
#endif

#endif // #ifndef FCE_CFG_H