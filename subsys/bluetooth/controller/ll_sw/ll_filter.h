/*
 * Copyright (c) 2017 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define WL_SIZE        8

#define RL_IDX_NONE    0xF

struct ll_filter {
	u8_t  enable_bitmask;
	u8_t  addr_type_bitmask;
	u8_t  bdaddr[WL_SIZE][BDADDR_SIZE];
};

void ll_filter_reset(bool init);
void ll_filters_adv_update(u8_t adv_fp);
void ll_filters_scan_update(u8_t scan_fp);

struct ll_filter *ctrl_filter_get(bool whitelist);
u8_t *ctrl_irks_get(u8_t *count);
bool ctrl_irk_whitelisted(u8_t irkmatch_id);
bool ctrl_rl_idx_match(u8_t irkmatch_id, u8_t rl_idx);

bool ctrl_rl_enabled(void);
void ll_rl_rpa_update(bool timeout);

int ll_rl_find(u8_t id_addr_type, u8_t *id_addr);
bool ctrl_rl_allowed(u8_t id_addr_type, u8_t *id_addr);
void ll_rl_pdu_adv_update(int idx, struct pdu_adv *pdu);
