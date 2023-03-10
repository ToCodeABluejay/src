/*	$OpenBSD: ldasm.S,v 1.26 2023/01/09 13:52:42 kettenis Exp $	*/

/*
 * Copyright (c) 2004 Michael Shalayeff
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/syscall.h>
#include <machine/asm.h>
#define	_LOCORE
#include <machine/frame.h>
#include <machine/vmparam.h>
#undef	_LOCORE

	.import	$global$, data

ENTRY(_dl_start,32)
	copy	r3, r1
	copy	sp, r3
	stwm	r1, HPPA_FRAME_SIZE+16*4(sp)

	stw	arg0, HPPA_FRAME_ARG(0)(r3)	/* ps_strings */

	bl	1f, r19
	depi	0, 31, 2, r19
1:	addil	L'$global$ - ($PIC_pcrel$0 - 8), r19
	ldo	R'$global$ - ($PIC_pcrel$0 - 12)(r1), r19
	bl	1f, arg2
	depi	0, 31, 2, arg2
1:	addil	L'_DYNAMIC - ($PIC_pcrel$0 - 8), arg2
	ldo	R'_DYNAMIC - ($PIC_pcrel$0 - 12)(r1), arg2
	stw	arg2, HPPA_FRAME_ARG(1)(r3)

	/* make sure to get a fault until it's set proper */
	ldi	-1, dp

	ldw	0(arg0), arg0
	ldo	4(r3), arg1			/* dl_data */
	bl	_dl_boot_bind, rp
	ldo	-4(arg0), arg0

	ldw	HPPA_FRAME_ARG(1)(r3), arg1	/* &_DYNAMIC */
	ldw	HPPA_FRAME_ARG(0)(r3), arg3	/* ps_strings */
	ldw	0(r19), arg2
	sub	arg1, arg2, arg2		/* loff */

	ldw	0(arg3), arg0			/* argv */
	ldw	8(arg3), arg1			/* envp */

	bl	_dl_boot, rp
	ldo	4(r3), arg3			/* dl_data */

	ldw	HPPA_FRAME_ARG(0)(r3), arg0	/* ps_strings */
	addil	LT'_dl_dtors_plabel, r19
	ldw	RT'_dl_dtors_plabel(r1), arg1
	ldw	0(arg1), arg1			/* cleanup */

	ldo	HPPA_FRAME_SIZE(r3), sp
	copy	r0, rp
	bv	r0(ret0)
	ldwm	-HPPA_FRAME_SIZE(sp), r3
EXIT(_dl_start)

	.section .data
	.align 4
_dl_dtors_plabel:
	.word P%_dl_dtors
	.previous

LEAF_ENTRY(_hppa_dl_set_dp)
	bv	r0(rp)
	copy	arg0, r27
EXIT(_hppa_dl_set_dp)

/*
 * This is a magic branch instruction that is used by GCC's
 * __canonicalize_funcptr_for_compare() function to fixup relocations
 * in order to do function pointer comparisons.
 */
	b	_dl_bind

ENTRY(_dl_bind_start,32)
	copy	r3, r1
	copy	sp, r3
	stwm	r1, HPPA_FRAME_SIZE(sp)

	stw	rp, HPPA_FRAME_CRP(r3)
	stw	arg0, HPPA_FRAME_ARG(0)(r3)
	stw	arg1, HPPA_FRAME_ARG(1)(r3)
	stw	arg2, HPPA_FRAME_ARG(2)(r3)
	stw	arg3, HPPA_FRAME_ARG(3)(r3)
	stw	t1, 4(r3)
	stw	ret0, 8(r3)
	stw	ret1, 12(r3)

	ldw	12(r20), arg0
	copy	r19, arg1

	bl	_dl_bind, rp
	copy	r21, r19

	copy	ret0, r21	/* &func */
	copy	ret1, r19	/* sl */

	ldw	HPPA_FRAME_ARG(0)(r3), arg0
	ldw	HPPA_FRAME_ARG(1)(r3), arg1
	ldw	HPPA_FRAME_ARG(2)(r3), arg2
	ldw	HPPA_FRAME_ARG(3)(r3), arg3
	ldw	4(r3), t1
	ldw	8(r3), ret0
	ldw	12(r3), ret1

	ldw	HPPA_FRAME_CRP(r3), rp
	ldo	HPPA_FRAME_SIZE(r3), sp
	bv	r0(r21)
	ldwm	-HPPA_FRAME_SIZE(sp), r3
EXIT(_dl_bind_start)

	.end
