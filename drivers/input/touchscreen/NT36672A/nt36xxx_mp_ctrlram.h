/*
 * Copyright (C) 2010 - 2018 Novatek, Inc.
 * Copyright (C) 2020 XiaoMi, Inc.
 *
 * $Revision: 52752 $
 * $Date: 2019-11-06 18:05:46 +0800 (周三, 06 11月 2019) $
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */

#if NVT_TOUCH_MP

static uint32_t IC_X_CFG_SIZE = 16;
static uint32_t IC_Y_CFG_SIZE = 36;
static uint32_t IC_KEY_CFG_SIZE = 4;
static uint32_t X_Channel = 16;
static uint32_t Y_Channel = 36;
static uint32_t Key_Channel = TOUCH_KEY_NUM;
static uint8_t AIN_X[40] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
static uint8_t AIN_Y[40] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
							18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
#if TOUCH_KEY_NUM > 0
static uint8_t AIN_KEY[8] = {0, 1, 2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
#endif /* #if TOUCH_KEY_NUM > 0 */

static int32_t PS_Config_Lmt_Short_Rawdata_P[40 * 40] = {
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
	14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,14008,
#if TOUCH_KEY_NUM > 0
	14008,14008,14008,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_Short_Rawdata_N[40 * 40] = {
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
	10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,
#if TOUCH_KEY_NUM > 0
	10000,10000,10000,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_Open_Rawdata_P[40 * 40] = {
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
	5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,5120,
#if TOUCH_KEY_NUM > 0
	5120,5120,5120,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_Open_Rawdata_N[40 * 40] = {
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
	-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,-511,
#if TOUCH_KEY_NUM > 0
	-511,-511,-511,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_Rawdata_P[40 * 40] = {
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
	2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,2560,
#if TOUCH_KEY_NUM > 0
	2560,2560,2560,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_Rawdata_N[40 * 40] = {
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
	240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,
#if TOUCH_KEY_NUM > 0
	240,240,240,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_CC_P[40 * 40] = {
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
	314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,
#if TOUCH_KEY_NUM > 0
	314,314,314,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_CC_N[40 * 40] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
#if TOUCH_KEY_NUM > 0
	0,0,0,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_Diff_P[40 * 40] = {
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
#if TOUCH_KEY_NUM > 0
	75,75,75,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_Diff_N[40 *40] = {
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
	-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,-75,
#if TOUCH_KEY_NUM > 0
	-75,-75,-75,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Diff_Test_Frame = 50;

#endif /* #if NVT_TOUCH_MP */
