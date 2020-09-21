;; SPDX-License-Identifier: GPL-2.0-or-later
;;
;; Define a generic monitor entry point for usage by C wrapper macros.
;;
;; Copyright (C) Dimitar Dimitrov <dimitar@dinux.eu>

	.module scmon_api1
	.globl	_scmon_api1

	.area	_CODE
_scmon_api1:
        ld      hl, #2+0
        add     hl, sp
        ld      c, (hl)		;; API function ID to call

        ld      hl, #3+0
        add     hl, sp
        ld      a, (hl)		;; API call parameter

        ld      hl, #4+0
        add     hl, sp
        ld      e, (hl)		;; API extra call parameter L
        ld      hl, #5+0
        add     hl, sp
        ld      d, (hl)		;; API extra call parameter H

	rst	0x30		;; Call API
	;;call	#0030

	ld	l, a		;; Return value, if any

        ret

