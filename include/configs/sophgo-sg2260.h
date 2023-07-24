/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2023 FIXME, Inc
 *
 */

#ifndef __SOPHGO_SG2260_H
#define __SOPHGO_SG2260_H

#include <linux/sizes.h>

#define UART_BASE	0x7040000000
#define UART_REG_WIDTH  32

/* Environment options */

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0)

#include <config_distro_bootcmd.h>

#define PARTS_DEFAULT \
	"name=loader1,start=17K,size=1M,type=${type_guid_gpt_loader1};" \
	"name=loader2,size=4MB,type=${type_guid_gpt_loader2};" \
	"name=system,size=-,bootable,type=${type_guid_gpt_system};"

#define CFG_EXTRA_ENV_SETTINGS \
	"kernel_addr_r=0x82000000\0" \
	"kernel_comp_addr_r=0x88000000\0" \
	"kernel_comp_size=0x4000000\0" \
	"ramdisk_addr_r=0x8d300000\0" \
	"fdt_addr_r=0x8e000000\0" \
	"fdt_addr_fixed=0x20000000\0" \
	"PS1=[Sophgo]# \0" \
	"bootargs=console=ttyS0,115200 earlycon ignore_loglevel rdinit=/init root=/dev/ram0 rw initrd=0x13000000,32M retain_initrd maxcpus=1 nvme.use_threaded_interrupts=1 nvme_core.io_timeout=3000\0" \
	BOOTENV

#endif /* __SOPHGO_SG2260_H */
