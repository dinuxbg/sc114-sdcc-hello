/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Example SDCC C program to show a binary counter. Tested on:
 *
 *   SC114 Z80 Motherboard Kit for RC2014
 *   SC129 Digital I/O Module Kit for RC2014
 *   SC104 Z80 SIO/2 Module Kit for RC2014
 *
 * Copyright (C) Dimitar Dimitrov <dimitar@dinux.eu>
 */

#include <stdint.h>
#include "scmon_api.h"

/* SC129 Digital I/O Module Kit for RC2014 */
__sfr __at 0x00 DIO;

/* On-board single LED. */
__sfr __at 0x08 LEDST;

void main(void)
{
	int n=0;

	while(1) {
		DIO=n++;

		scmon_delay_ms(900);
		LEDST = 0;
		scmon_delay_ms(100);
		LEDST = 1;

		scmon_putline("....\n");
	}
}

