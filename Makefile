# SPDX-License-Identifier: GPL-2.0-or-later
# Copyright (C) Dimitar Dimitrov <dimitar@dinux.eu>

OBJS := scmon_api.rel main.rel

# Keep CRT0 first in link order.
main.s: crt0.rel $(OBJS)
	sdcc -mz80                            \
		--code-loc 0x8000             \
		--data-loc 0x9000             \
		--no-std-crt0 \
		-V --verbose \
		$^ \
		-o $@

%.rel: %.S
	sdasz80 -o $@ $<

%.rel: %.c
	sdcc -mz80 -c -o $@ $<

run: main.s
	cat $^ > /dev/ttyUSB0
	sleep 1
	/bin/echo -e "g 8000\r" > /dev/ttyUSB0

clean:
	rm -f *.rel *.asm *.lk *.lst *.map *.noi *.s *.sym

.PHONY: clean run
