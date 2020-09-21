/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * C wrapper macros for accessing Small Computer Monitor's API [1].
 * I have tested with version 1.0.
 *
 * [1] https://smallcomputercentral.wordpress.com/small-computer-monitor/
 *
 * Copyright (C) Dimitar Dimitrov <dimitar@dinux.eu>
 */

#include <stdint.h>

/*
 * WARNING: This C interface does not support all monitor API variants!
 * Some API function calls pass parameters and return values in
 * areas not supported by this wrapper! So be sure to carefully check
 * when adding new API C helpers.
 */
extern uint8_t scmon_api1(uint8_t funcid, uint8_t param1, uint16_t param2);

enum scmon_rst_type {
	SCMON_RST_COLD,
	SCMON_RST_WARM
};


static inline void scmon_reset(enum scmon_rst_type t)
{
	scmon_api1(0, t, 0);
}

static inline char scmon_getchar(void)
{
	return scmon_api1(1, 0, 0);
}

static inline void scmon_putchar(char c)
{
	scmon_api1(2, c, 0);
}

static inline uint8_t scmon_getline(uint8_t max_size, uint8_t *ptr)
{
	return scmon_api1(4, max_size, (uint16_t)(ptr));
}

static inline void scmon_putline(char *ptr)
{
	scmon_api1(6, 0, (uint16_t)(ptr));
}
static inline void scmon_newline(void)
{
	scmon_api1(7, 0, 0);
}
static inline void scmon_delay_ms(uint16_t ms)
{
	scmon_api1(0x0A, 0, ms);
}
