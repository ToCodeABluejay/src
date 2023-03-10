/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 * DONT EDIT THIS FILE
 */

/*	$OpenBSD: cn30xxciureg.h,v 1.3 2022/12/28 01:39:21 yasuoka Exp $	*/

/*
 * Copyright (c) 2007 Internet Initiative Japan, Inc.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Cavium Networks OCTEON CN30XX Hardware Reference Manual
 * CN30XX-HM-1.0
 * 11.10 CIU Registers
 */

#ifndef _CN30XXCIUREG_H_
#define _CN30XXCIUREG_H_

/* ---- register addresses */

#define	CIU_INT0_SUM0				0x0001070000000000ULL
#define	CIU_INT1_SUM0				0x0001070000000008ULL
#define	CIU_INT2_SUM0				0x0001070000000010ULL
#define	CIU_INT3_SUM0				0x0001070000000018ULL
#define	CIU_INT32_SUM0				0x0001070000000100ULL
#define	CIU_INT_SUM1				0x0001070000000008ULL
#define	CIU_INT0_EN0				0x0001070000000200ULL
#define	CIU_INT1_EN0				0x0001070000000210ULL
#define	CIU_INT2_EN0				0x0001070000000220ULL
#define	CIU_INT3_EN0				0x0001070000000230ULL
#define	CIU_INT32_EN0				0x0001070000000400ULL
#define	CIU_INT0_EN1				0x0001070000000208ULL
#define	CIU_INT1_EN1				0x0001070000000218ULL
#define	CIU_INT2_EN1				0x0001070000000228ULL
#define	CIU_INT3_EN1				0x0001070000000238ULL
#define	CIU_INT32_EN1				0x0001070000000408ULL
#define	CIU_TIM0				0x0001070000000480ULL
#define	CIU_TIM1				0x0001070000000488ULL
#define	CIU_TIM2				0x0001070000000490ULL
#define	CIU_TIM3				0x0001070000000498ULL
#define	CIU_WDOG0				0x0001070000000500ULL
#define	CIU_WDOG1				0x0001070000000508ULL
#define	CIU_PP_POKE0				0x0001070000000580ULL
#define	CIU_PP_POKE1				0x0001070000000588ULL
#define	CIU_MBOX_SET0				0x0001070000000600ULL
#define	CIU_MBOX_SET1				0x0001070000000600ULL
#define	CIU_MBOX_CLR0				0x0001070000000680ULL
#define	CIU_MBOX_CLR1				0x0001070000000680ULL
#define	CIU_PP_RST				0x0001070000000700ULL
#define	CIU_PP_DBG				0x0001070000000708ULL
#define	CIU_GSTOP				0x0001070000000710ULL
#define	CIU_NMI					0x0001070000000718ULL
#define	CIU_DINT				0x0001070000000720ULL
#define	CIU_FUSE				0x0001070000000728ULL
#define	CIU_BIST				0x0001070000000730ULL
#define	CIU_SOFT_BIST				0x0001070000000738ULL
#define	CIU_SOFT_RST				0x0001070000000740ULL
#define	CIU_SOFT_PRST				0x0001070000000748ULL
#define	CIU_PCI_INTA				0x0001070000000750ULL

#define	CIU_INT0_SUM0_OFFSET			0x0000
#define	CIU_INT1_SUM0_OFFSET			0x0008
#define	CIU_INT2_SUM0_OFFSET			0x0010
#define	CIU_INT3_SUM0_OFFSET			0x0018
#define	CIU_INT32_SUM0_OFFSET			0x0100
#define	CIU_INT_SUM1_OFFSET			0x0008
#define	CIU_INT0_EN0_OFFSET			0x0200
#define	CIU_INT1_EN0_OFFSET			0x0210
#define	CIU_INT2_EN0_OFFSET			0x0220
#define	CIU_INT3_EN0_OFFSET			0x0230
#define	CIU_INT32_EN0_OFFSET			0x0400
#define	CIU_INT0_EN1_OFFSET			0x0208
#define	CIU_INT1_EN1_OFFSET			0x0218
#define	CIU_INT2_EN1_OFFSET			0x0228
#define	CIU_INT3_EN1_OFFSET			0x0238
#define	CIU_INT32_EN1_OFFSET			0x0408
#define	CIU_TIM0_OFFSET				0x0480
#define	CIU_TIM1_OFFSET				0x0488
#define	CIU_TIM2_OFFSET				0x0490
#define	CIU_TIM3_OFFSET				0x0498
#define	CIU_WDOG0_OFFSET			0x0500
#define	CIU_WDOG1_OFFSET			0x0508
#define	CIU_PP_POKE0_OFFSET			0x0580
#define	CIU_PP_POKE1_OFFSET			0x0588
#define	CIU_MBOX_SET0_OFFSET			0x0600
#define	CIU_MBOX_SET1_OFFSET			0x0608
#define	CIU_MBOX_CLR0_OFFSET			0x0680
#define	CIU_MBOX_CLR1_OFFSET			0x0688
#define	CIU_PP_RST_OFFSET			0x0700
#define	CIU_PP_DBG_OFFSET			0x0708
#define	CIU_GSTOP_OFFSET			0x0710
#define	CIU_NMI_OFFSET				0x0718
#define	CIU_DINT_OFFSET				0x0720
#define	CIU_FUSE_OFFSET				0x0728
#define	CIU_BIST_OFFSET				0x0730
#define	CIU_SOFT_BIST_OFFSET			0x0738
#define	CIU_SOFT_RST_OFFSET			0x0740
#define	CIU_SOFT_PRST_OFFSET			0x0748
#define	CIU_PCI_INTA_OFFSET			0x0750

/* ---- register bits */

/* ``interrupt bits'' shift values */

#define	_CIU_INT_XXX_63_SHIFT			0x3f
#define	_CIU_INT_XXX_62_SHIFT			0x3e
#define	_CIU_INT_XXX_61_SHIFT			0x3d
#define	_CIU_INT_XXX_60_SHIFT			0x3c
#define	_CIU_INT_XXX_59_SHIFT			0x3b
#define	_CIU_INT_MPI_SHIFT			0x3a
#define	_CIU_INT_PCM_SHIFT			0x39
#define	_CIU_INT_USB_SHIFT			0x38
#define	_CIU_INT_TIMER_3_SHIFT			0x37
#define	_CIU_INT_TIMER_2_SHIFT			0x36
#define	_CIU_INT_TIMER_1_SHIFT			0x35
#define	_CIU_INT_TIMER_0_SHIFT			0x34
#define	_CIU_INT_XXX_51_SHIFT			0x33
#define	_CIU_INT_IPD_DRP_SHIFT			0x32
#define	_CIU_INT_GMX_DRP_SHIFT			0x30
#define	_CIU_INT_TRACE_SHIFT			0x2f
#define	_CIU_INT_RML_SHIFT			0x2e
#define	_CIU_INT_TWSI_SHIFT			0x2d
#define	_CIU_INT_WDOG_SUM_SHIFT			0x2c
#define	_CIU_INT_PCI_MSI_63_48_SHIFT		0x2b
#define	_CIU_INT_PCI_MSI_47_32_SHIFT		0x2a
#define	_CIU_INT_PCI_MSI_31_16_SHIFT		0x29
#define	_CIU_INT_PCI_MSI_15_0_SHIFT		0x28
#define	_CIU_INT_PCI_INT_D_SHIFT		0x27
#define	_CIU_INT_PCI_INT_C_SHIFT		0x26
#define	_CIU_INT_PCI_INT_B_SHIFT		0x25
#define	_CIU_INT_PCI_INT_A_SHIFT		0x24
#define	_CIU_INT_UART_1_SHIFT			0x23
#define	_CIU_INT_UART_0_SHIFT			0x22
#define	_CIU_INT_MBOX_31_16_SHIFT		0x21
#define	_CIU_INT_MBOX_15_0_SHIFT		0x20
#define	_CIU_INT_GPIO_15_SHIFT			0x1f
#define	_CIU_INT_GPIO_14_SHIFT			0x1e
#define	_CIU_INT_GPIO_13_SHIFT			0x1d
#define	_CIU_INT_GPIO_12_SHIFT			0x1c
#define	_CIU_INT_GPIO_11_SHIFT			0x1b
#define	_CIU_INT_GPIO_10_SHIFT			0x1a
#define	_CIU_INT_GPIO_9_SHIFT			0x19
#define	_CIU_INT_GPIO_8_SHIFT			0x18
#define	_CIU_INT_GPIO_7_SHIFT			0x17
#define	_CIU_INT_GPIO_6_SHIFT			0x16
#define	_CIU_INT_GPIO_5_SHIFT			0x15
#define	_CIU_INT_GPIO_4_SHIFT			0x14
#define	_CIU_INT_GPIO_3_SHIFT			0x13
#define	_CIU_INT_GPIO_2_SHIFT			0x12
#define	_CIU_INT_GPIO_1_SHIFT			0x11
#define	_CIU_INT_GPIO_0_SHIFT			0x10
#define	_CIU_INT_WORKQ_15_SHIFT			0x0f
#define	_CIU_INT_WORKQ_14_SHIFT			0x0e
#define	_CIU_INT_WORKQ_13_SHIFT			0x0d
#define	_CIU_INT_WORKQ_12_SHIFT			0x0c
#define	_CIU_INT_WORKQ_11_SHIFT			0x0b
#define	_CIU_INT_WORKQ_10_SHIFT			0x0a
#define	_CIU_INT_WORKQ_9_SHIFT			0x09
#define	_CIU_INT_WORKQ_8_SHIFT			0x08
#define	_CIU_INT_WORKQ_7_SHIFT			0x07
#define	_CIU_INT_WORKQ_6_SHIFT			0x06
#define	_CIU_INT_WORKQ_5_SHIFT			0x05
#define	_CIU_INT_WORKQ_4_SHIFT			0x04
#define	_CIU_INT_WORKQ_3_SHIFT			0x03
#define	_CIU_INT_WORKQ_2_SHIFT			0x02
#define	_CIU_INT_WORKQ_1_SHIFT			0x01

#define	CIU_INTX_SUM0_XXX_63_59			0xf800000000000000ULL
#define	CIU_INTX_SUM0_MPI			0x0400000000000000ULL
#define	CIU_INTX_SUM0_PCM			0x0200000000000000ULL
#define	CIU_INTX_SUM0_USB			0x0100000000000000ULL
#define	CIU_INTX_SUM0_TIMER			0x00f0000000000000ULL
#define	 CIU_INTX_SUM0_TIMER_3			0x0080000000000000ULL
#define	 CIU_INTX_SUM0_TIMER_2			0x0040000000000000ULL
#define	 CIU_INTX_SUM0_TIMER_1			0x0020000000000000ULL
#define	 CIU_INTX_SUM0_TIMER_0			0x0010000000000000ULL
#define	CIU_INTX_SUM0_XXX_51			0x0008000000000000ULL
#define	CIU_INTX_SUM0_IPD_DRP			0x0004000000000000ULL
#define	CIU_INTX_SUM0_XXX_49			0x0002000000000000ULL
#define	CIU_INTX_SUM0_GMX_DRP			0x0001000000000000ULL
#define	CIU_INTX_SUM0_TRACE			0x0000800000000000ULL
#define	CIU_INTX_SUM0_RML			0x0000400000000000ULL
#define	CIU_INTX_SUM0_TWSI			0x0000200000000000ULL
#define	CIU_INTX_SUM0_WDOG_SUM			0x0000100000000000ULL
#define	CIU_INTX_SUM0_PCI_MSI			0x00000f0000000000ULL
#define	 CIU_INTX_SUM0_PCI_MSI_63_48		0x0000080000000000ULL
#define	 CIU_INTX_SUM0_PCI_MSI_47_32		0x0000040000000000ULL
#define	 CIU_INTX_SUM0_PCI_MSI_31_16		0x0000020000000000ULL
#define	 CIU_INTX_SUM0_PCI_MSI_15_0		0x0000010000000000ULL
#define	CIU_INTX_SUM0_PCI_INT			0x000000f000000000ULL
#define	 CIU_INTX_SUM0_PCI_INT_D		0x0000008000000000ULL
#define	 CIU_INTX_SUM0_PCI_INT_C		0x0000004000000000ULL
#define	 CIU_INTX_SUM0_PCI_INT_B		0x0000002000000000ULL
#define	 CIU_INTX_SUM0_PCI_INT_A		0x0000001000000000ULL
#define	CIU_INTX_SUM0_UART			0x0000000c00000000ULL
#define	 CIU_INTX_SUM0_UART_1			0x0000000800000000ULL
#define	 CIU_INTX_SUM0_UART_0			0x0000000400000000ULL
#define	CIU_INTX_SUM0_MBOX			0x0000000300000000ULL
#define	 CIU_INTX_SUM0_MBOX_31_16		0x0000000200000000ULL
#define	 CIU_INTX_SUM0_MBOX_15_0		0x0000000100000000ULL
#define	CIU_INTX_SUM0_GPIO			0x00000000ffff0000ULL
#define	 CIU_INTX_SUM0_GPIO_15			0x0000000080000000ULL
#define	 CIU_INTX_SUM0_GPIO_14			0x0000000040000000ULL
#define	 CIU_INTX_SUM0_GPIO_13			0x0000000020000000ULL
#define	 CIU_INTX_SUM0_GPIO_12			0x0000000010000000ULL
#define	 CIU_INTX_SUM0_GPIO_11			0x0000000008000000ULL
#define	 CIU_INTX_SUM0_GPIO_10			0x0000000004000000ULL
#define	 CIU_INTX_SUM0_GPIO_9			0x0000000002000000ULL
#define	 CIU_INTX_SUM0_GPIO_8			0x0000000001000000ULL
#define	 CIU_INTX_SUM0_GPIO_7			0x0000000000800000ULL
#define	 CIU_INTX_SUM0_GPIO_6			0x0000000000400000ULL
#define	 CIU_INTX_SUM0_GPIO_5			0x0000000000200000ULL
#define	 CIU_INTX_SUM0_GPIO_4			0x0000000000100000ULL
#define	 CIU_INTX_SUM0_GPIO_3			0x0000000000080000ULL
#define	 CIU_INTX_SUM0_GPIO_2			0x0000000000040000ULL
#define	 CIU_INTX_SUM0_GPIO_1			0x0000000000020000ULL
#define	 CIU_INTX_SUM0_GPIO_0			0x0000000000010000ULL
#define	CIU_INTX_SUM0_WORKQ			0x000000000000ffffULL
#define	 CIU_INTX_SUM0_WORKQ_15			0x0000000000008000ULL
#define	 CIU_INTX_SUM0_WORKQ_14			0x0000000000004000ULL
#define	 CIU_INTX_SUM0_WORKQ_13			0x0000000000002000ULL
#define	 CIU_INTX_SUM0_WORKQ_12			0x0000000000001000ULL
#define	 CIU_INTX_SUM0_WORKQ_11			0x0000000000000800ULL
#define	 CIU_INTX_SUM0_WORKQ_10			0x0000000000000400ULL
#define	 CIU_INTX_SUM0_WORKQ_9			0x0000000000000200ULL
#define	 CIU_INTX_SUM0_WORKQ_8			0x0000000000000100ULL
#define	 CIU_INTX_SUM0_WORKQ_7			0x0000000000000080ULL
#define	 CIU_INTX_SUM0_WORKQ_6			0x0000000000000040ULL
#define	 CIU_INTX_SUM0_WORKQ_5			0x0000000000000020ULL
#define	 CIU_INTX_SUM0_WORKQ_4			0x0000000000000010ULL
#define	 CIU_INTX_SUM0_WORKQ_3			0x0000000000000008ULL
#define	 CIU_INTX_SUM0_WORKQ_2			0x0000000000000004ULL
#define	 CIU_INTX_SUM0_WORKQ_1			0x0000000000000002ULL
#define	 CIU_INTX_SUM0_WORKQ_0			0x0000000000000001ULL

#define	CIU_INT_SUM1_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_INT_SUM1_WDOG			0x0000000000000001ULL

#define	CIU_INTX_EN0_XXX_63_59			0xf800000000000000ULL
#define	CIU_INTX_EN0_MPI			0x0400000000000000ULL
#define	CIU_INTX_EN0_PCM			0x0200000000000000ULL
#define	CIU_INTX_EN0_USB			0x0100000000000000ULL
#define	CIU_INTX_EN0_TIMER			0x00f0000000000000ULL
#define	 CIU_INTX_EN0_TIMER_3			0x0080000000000000ULL
#define	 CIU_INTX_EN0_TIMER_2			0x0040000000000000ULL
#define	 CIU_INTX_EN0_TIMER_1			0x0020000000000000ULL
#define	 CIU_INTX_EN0_TIMER_0			0x0010000000000000ULL
#define	CIU_INTX_EN0_XXX_51			0x0008000000000000ULL
#define	CIU_INTX_EN0_IPD_DRP			0x0004000000000000ULL
#define	CIU_INTX_EN0_XXX_49			0x0002000000000000ULL
#define	CIU_INTX_EN0_GMX_DRP			0x0001000000000000ULL
#define	CIU_INTX_EN0_TRACE			0x0000800000000000ULL
#define	CIU_INTX_EN0_RML			0x0000400000000000ULL
#define	CIU_INTX_EN0_TWSI			0x0000200000000000ULL
#define	CIU_INTX_EN0_WDOG_SUM			0x0000100000000000ULL
#define	CIU_INTX_EN0_PCI_MSI			0x00000f0000000000ULL
#define	 CIU_INTX_EN0_PCI_MSI_63_48		0x0000080000000000ULL
#define	 CIU_INTX_EN0_PCI_MSI_47_32		0x0000040000000000ULL
#define	 CIU_INTX_EN0_PCI_MSI_31_16		0x0000020000000000ULL
#define	 CIU_INTX_EN0_PCI_MSI_15_0		0x0000010000000000ULL
#define	CIU_INTX_EN0_PCI_INT			0x000000f000000000ULL
#define	 CIU_INTX_EN0_PCI_INT_D			0x0000008000000000ULL
#define	 CIU_INTX_EN0_PCI_INT_C			0x0000004000000000ULL
#define	 CIU_INTX_EN0_PCI_INT_B			0x0000002000000000ULL
#define	 CIU_INTX_EN0_PCI_INT_A			0x0000001000000000ULL
#define	CIU_INTX_EN0_UART			0x0000000c00000000ULL
#define	 CIU_INTX_EN0_UART_1			0x0000000800000000ULL
#define	 CIU_INTX_EN0_UART_0			0x0000000400000000ULL
#define	CIU_INTX_EN0_MBOX			0x0000000300000000ULL
#define	 CIU_INTX_EN0_MBOX_31_16		0x0000000200000000ULL
#define	 CIU_INTX_EN0_MBOX_15_0			0x0000000100000000ULL
#define	CIU_INTX_EN0_GPIO			0x00000000ffff0000ULL
#define	 CIU_INTX_EN0_GPIO_15			0x0000000080000000ULL
#define	 CIU_INTX_EN0_GPIO_14			0x0000000040000000ULL
#define	 CIU_INTX_EN0_GPIO_13			0x0000000020000000ULL
#define	 CIU_INTX_EN0_GPIO_12			0x0000000010000000ULL
#define	 CIU_INTX_EN0_GPIO_11			0x0000000008000000ULL
#define	 CIU_INTX_EN0_GPIO_10			0x0000000004000000ULL
#define	 CIU_INTX_EN0_GPIO_9			0x0000000002000000ULL
#define	 CIU_INTX_EN0_GPIO_8			0x0000000001000000ULL
#define	 CIU_INTX_EN0_GPIO_7			0x0000000000800000ULL
#define	 CIU_INTX_EN0_GPIO_6			0x0000000000400000ULL
#define	 CIU_INTX_EN0_GPIO_5			0x0000000000200000ULL
#define	 CIU_INTX_EN0_GPIO_4			0x0000000000100000ULL
#define	 CIU_INTX_EN0_GPIO_3			0x0000000000080000ULL
#define	 CIU_INTX_EN0_GPIO_2			0x0000000000040000ULL
#define	 CIU_INTX_EN0_GPIO_1			0x0000000000020000ULL
#define	 CIU_INTX_EN0_GPIO_0			0x0000000000010000ULL
#define	CIU_INTX_EN0_WORKQ			0x000000000000ffffULL
#define	 CIU_INTX_EN0_WORKQ_15			0x0000000000008000ULL
#define	 CIU_INTX_EN0_WORKQ_14			0x0000000000004000ULL
#define	 CIU_INTX_EN0_WORKQ_13			0x0000000000002000ULL
#define	 CIU_INTX_EN0_WORKQ_12			0x0000000000001000ULL
#define	 CIU_INTX_EN0_WORKQ_11			0x0000000000000800ULL
#define	 CIU_INTX_EN0_WORKQ_10			0x0000000000000400ULL
#define	 CIU_INTX_EN0_WORKQ_9			0x0000000000000200ULL
#define	 CIU_INTX_EN0_WORKQ_8			0x0000000000000100ULL
#define	 CIU_INTX_EN0_WORKQ_7			0x0000000000000080ULL
#define	 CIU_INTX_EN0_WORKQ_6			0x0000000000000040ULL
#define	 CIU_INTX_EN0_WORKQ_5			0x0000000000000020ULL
#define	 CIU_INTX_EN0_WORKQ_4			0x0000000000000010ULL
#define	 CIU_INTX_EN0_WORKQ_3			0x0000000000000008ULL
#define	 CIU_INTX_EN0_WORKQ_2			0x0000000000000004ULL
#define	 CIU_INTX_EN0_WORKQ_1			0x0000000000000002ULL
#define	 CIU_INTX_EN0_WORKQ_0			0x0000000000000001ULL

#define	CIU_INTX_EN1_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_INTX_EN1_WDOG			0x0000000000000001ULL

#define	CIU_TIMX_XXX_63_37			0xffffffe000000000ULL
#define	CIU_TIMX_ONE_SHOT			0x0000001000000000ULL
#define	CIU_TIMX_LEN				0x0000000fffffffffULL

#define	CIU_WDOGX_XXX_63_46			0xffffc00000000000ULL
#define	CIU_WDOGX_GSTOPEN			0x0000200000000000ULL
#define	CIU_WDOGX_DSTOP				0x0000100000000000ULL
#define	CIU_WDOGX_CNT				0x00000ffffff00000ULL
#define	CIU_WDOGX_LEN				0x00000000000ffff0ULL
#define	CIU_WDOGX_STATE				0x000000000000000cULL
#define	CIU_WDOGX_MODE				0x0000000000000003ULL

#define	CIU_PP_POKEX_XXX_63_0			0xffffffffffffffffULL

#define	CIU_MBOX_SETX_XXX_63_32			0xffffffff00000000ULL
#define	CIU_MBOX_SETX_SET			0x00000000ffffffffULL

#define	CIU_MBOX_CLRX_XXX_63_32			0xffffffff00000000ULL
#define	CIU_MBOX_CLRX_CLR			0x00000000ffffffffULL

#define	CIU_PP_RST_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_PP_RST_RST0				0x0000000000000001ULL

#define	CIU_PP_DBG_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_PP_DBG_PPDBG			0x0000000000000001ULL

#define	CIU_GSTOP_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_GSTOP_GSTOP				0x0000000000000001ULL

#define	CIU_NMI_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_NMI_NMI				0x0000000000000001ULL

#define	CIU_DINT_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_DINT_DINT				0x0000000000000001ULL

#define	CIU_FUSE_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_FUSE_FUSE				0x0000000000000001ULL

#define	CIU_BIST_XXX_63_4			0xfffffffffffffff0ULL
#define	CIU_BIST_BIST				0x000000000000000fULL

#define	CIU_SOFT_BIST_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_SOFT_BIST_SOFT_BIST			0x0000000000000001ULL

#define	CIU_SOFT_RST_XXX_63_1			0xfffffffffffffffeULL
#define	CIU_SOFT_RST_SOFT_RST			0x0000000000000001ULL

#define	CIU_SOFT_PRST_XXX_63_1			0xfffffffffffffff8ULL
#define	CIU_SOFT_PRST_HOST64			0x0000000000000004ULL
#define	CIU_SOFT_PRST_NPI			0x0000000000000002ULL
#define	CIU_SOFT_PRST_SOFT_PRST			0x0000000000000001ULL

#define	CIU_PCI_INTA_XXX_63_2			0xfffffffffffffffcULL
#define	CIU_PCI_INTA_INT			0x0000000000000003ULL

#endif /* _CN30XXCIUREG_H_ */
