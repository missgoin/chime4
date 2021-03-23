
/*
 * Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */



#ifndef _RX_PPDU_START_USER_INFO_H_
#define _RX_PPDU_START_USER_INFO_H_
#if !defined(__ASSEMBLER__)
#endif

#include "receive_user_info.h"

#define NUM_OF_DWORDS_RX_PPDU_START_USER_INFO 3

struct rx_ppdu_start_user_info {
    struct            receive_user_info                       receive_user_info_details;
};

#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_PHY_PPDU_ID_OFFSET 0x00000000
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_PHY_PPDU_ID_LSB 0
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_PHY_PPDU_ID_MASK 0x0000ffff

#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_USER_RSSI_OFFSET 0x00000000
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_USER_RSSI_LSB 16
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_USER_RSSI_MASK 0x00ff0000

#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_PKT_TYPE_OFFSET 0x00000000
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_PKT_TYPE_LSB 24
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_PKT_TYPE_MASK 0x0f000000

#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_STBC_OFFSET 0x00000000
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_STBC_LSB 28
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_STBC_MASK 0x10000000

#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_RECEPTION_TYPE_OFFSET 0x00000000
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_RECEPTION_TYPE_LSB 29
#define RX_PPDU_START_USER_INFO_0_RECEIVE_USER_INFO_DETAILS_RECEPTION_TYPE_MASK 0xe0000000

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_RATE_MCS_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_RATE_MCS_LSB 0
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_RATE_MCS_MASK 0x0000000f

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_SGI_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_SGI_LSB  4
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_SGI_MASK 0x00000030

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_RECEIVE_BANDWIDTH_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_RECEIVE_BANDWIDTH_LSB 6
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_RECEIVE_BANDWIDTH_MASK 0x000000c0

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_MIMO_SS_BITMAP_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_MIMO_SS_BITMAP_LSB 8
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_MIMO_SS_BITMAP_MASK 0x0000ff00

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_RU_ALLOCATION_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_RU_ALLOCATION_LSB 16
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_RU_ALLOCATION_MASK 0x00ff0000

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_USER_INDEX_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_USER_INDEX_LSB 24
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_USER_INDEX_MASK 0x7f000000

#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_CONTENT_CHANNEL_OFFSET 0x00000004
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_CONTENT_CHANNEL_LSB 31
#define RX_PPDU_START_USER_INFO_1_RECEIVE_USER_INFO_DETAILS_OFDMA_CONTENT_CHANNEL_MASK 0x80000000

#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_LDPC_OFFSET 0x00000008
#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_LDPC_LSB 0
#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_LDPC_MASK 0x00000001

#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_RU_WIDTH_OFFSET 0x00000008
#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_RU_WIDTH_LSB 1
#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_RU_WIDTH_MASK 0x000000fe

#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_RESERVED_2A_OFFSET 0x00000008
#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_RESERVED_2A_LSB 8
#define RX_PPDU_START_USER_INFO_2_RECEIVE_USER_INFO_DETAILS_RESERVED_2A_MASK 0xffffff00

#endif