/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the SAMSUNG SMDK2410 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T		1	/* This is an ARM920T Core	*/

//#define	CONFIG_S3C2410		1	/* in a SAMSUNG S3C2410 SoC     */
//#define CONFIG_SMDK2410		1	/* on a SAMSUNG SMDK2410 Board  */

#define CONFIG_S3C2440  1 /* in a SAMSUNG S3C2440 SoC     */
#define CONFIG_MINI2440  1 /* on a SAMSUNG MINI2440 Board  */
#define CONFIG_MINI2440_LED 1  /* mini2440 led on/off */
/* input clock of PLL */
#define CONFIG_SYS_CLK_FREQ	12000000/* the SMDK2410 has 12MHz input clock */


#define USE_920T_MMU		1
#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 128*1024)
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
 #if 0
#define CONFIG_DRIVER_CS8900	1	/* we have a CS8900 on-board */
#define CS8900_BASE		0x19000300
#define CS8900_BUS16		1 /* the Linux driver does accesses as shorts */
#endif
#define CONFIG_NET_MULTI  1
#define CONFIG_DRIVER_DM9000 1
#define CONFIG_DM9000_BASE 0x20000300 //网卡片选地址
#define DM9000_IO CONFIG_DM9000_BASE
#define DM9000_DATA (CONFIG_DM9000_BASE+4) //网卡数据地址
#define CONFIG_DM9000_NO_SROM  1
//#define CONFIG_DM9000_USE_16BIT
#undef CONFIG_DM9000_DEBUG
/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on SMDK2410 */

/************************************************************
 * RTC
 ************************************************************/
#define	CONFIG_RTC_S3C24X0	1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200


/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME


/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_CACHE
#define CONFIG_CMD_DATE
#define CONFIG_CMD_ELF

#define CONFIG_CMD_NAND
//#define CONFIG_CMD_JFFS2  /* JFFS2 Support*/
#define CONFIG_CMD_JFFS2  /* JFFS2 Support*/
#define CONFIG_CMD_PING /*ping command support*/

#define CONFIG_BOOTDELAY	3
#define CONFIG_SETUP_MEMORY_TAGS     1 //如果没有定义这个参数，则uboot参数必须加入men=内存大小
#define CONFIG_INITRD_TAG            1
#define CONFIG_CMDLINE_TAG           1 //设置bootargs出入内核必须
#define CONFIG_BOOTARGS "noinitrd console=ttySAC0,115200  init=/linuxrc \
root=/dev/mtdblock3 rw rootfstype=yaffs \
ip=10.1.0.129:10.1.0.128:10.1.0.1:255.255.255.0::eth0:off"

/* "noinitrd console=ttySAC0,115200 init=/linuxrc mem=64M \
 root=/dev/nfs rw nfsroot=10.1.0.128:/nfsboot \
 ip=10.1.0.129:10.1.128:10.1.0.1:255.255.255.0::eth0:off"
 */
/*#define CONFIG_BOOTARGS	"root=ramfs devfs=mount console=ttySA0,9600" */
#define CONFIG_ETHADDR	08:00:3e:26:0a:5b */
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_IPADDR		10.0.0.110
#define CONFIG_SERVERIP		10.0.0.1
#define CONFIG_GATEWAYIP 10.1.0.1
#define CONFIG_OVERWRITE_ETHADDR_ONCE
/*#define CONFIG_BOOTFILE	"elinos-lart" */
#define CONFIG_BOOTCOMMAND "nand read 0x30008000 0x80000 0x300000;bootm 0x30008000"
/*"nfs 0x30008000 10.1.0.128:/nfsboot/zImage.img;bootm" */
/*#define CONFIG_BOOTCOMMAND	"tftp; bootm" */
#define ENABLE_CMD_LOADB_X    1 //使能串口传输数据到内存的操作

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200		/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX	1		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define	CONFIG_SYS_LONGHELP				/* undef to save memory		*/
#define	CONFIG_SYS_PROMPT		"[u-boot@MINI2440]# "	/* Monitor Command Prompt	*/
#define	CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */
#define	CONFIG_SYS_MAXARGS		16		/* max number of command args	*/
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size	*/

#define CONFIG_SYS_MEMTEST_START	0x30000000	/* memtest works on	*/
#define CONFIG_SYS_MEMTEST_END		0x33F00000	/* 63 MB in DRAM	*/

#define	CONFIG_SYS_LOAD_ADDR		0x33000000	/* default load address	*/

/* the PWM TImer 4 uses a counter of 15625 for 10 ms, so we need */
/* it to wrap 100 times (total 1562500) to get 1 sec. */
#define	CONFIG_SYS_HZ			1562500

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	   /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x04000000 /* 64 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #1 */

#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#if 0
#define CONFIG_AMD_LV400	1	/* uncomment this if you have a LV400 flash */
#define CONFIG_AMD_LV800	1	/* uncomment this if you have a LV800 flash */
#endif
#define CONFIG_SST_39VF1601        1        //添加mini2440开发板Nor Flash设置
#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks */

#ifdef CONFIG_AMD_LV800
#define PHYS_FLASH_SIZE		0x00100000 /* 1MB */
#define CONFIG_SYS_MAX_FLASH_SECT	(19)	/* max number of sectors on one chip */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + 0x0F0000) /* addr of environment */
#endif
#ifdef CONFIG_AMD_LV400
#define PHYS_FLASH_SIZE		0x00080000 /* 512KB */
#define CONFIG_SYS_MAX_FLASH_SECT	(11)	/* max number of sectors on one chip */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + 0x070000) /* addr of environment */
#endif

#ifdef CONFIG_SST_39VF1601
#define PHYS_FLASH_SIZE  0x00200000 /* 2MB */
#define CONFIG_SYS_MAX_FLASH_SECT (35) /* max number of sectors on one chip */
//#define CONFIG_ENV_ADDR (CONFIG_SYS_FLASH_BASE + CONFIG_ENV_OFFSET) /* addr of environment */
#define CONFIG_ENV_ADDR (CONFIG_SYS_FLASH_BASE + CONFIG_ENV_OFFSET)
#endif

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(5*CONFIG_SYS_HZ) /* Timeout for Flash Erase */
#define CONFIG_SYS_FLASH_WRITE_TOUT	(5*CONFIG_SYS_HZ) /* Timeout for Flash Write */

//#define	CONFIG_ENV_IS_IN_FLASH	1
//#define CONFIG_ENV_SIZE		0x10000	/* Total Size of Environment Sector */
/*-----------------------------------------------------------------------
/*-----------------------------------------------------------------------
 * NAND flash settings
 */
#define CONFIG_ENV_IS_IN_NAND  1
#define CONFIG_ENV_OFFSET      0x40000 //将环境变量保存到nand中的0x40000位置必，须在块的起始位置
#define CONFIG_ENV_SIZE        0x20000 

#define CONFIG_S3C2410_NAND_SKIP_BAD 1
/*
 * Nand flash register and envionment variables 
 */
#define CONFIG_S3C2440_NAND_BOOT  1

#define NAND_CTL_BASE  0x4E000000  //Nand Flash配置寄存器基地址，查2440手册可得知

#define STACK_BASE  0x33F00000     //定义堆栈的地址
#define STACK_SIZE  0x8000         //堆栈的长度大小

#define oNFCONF  0x00 //相对Nand配置寄存器基地址的偏移量，还是配置寄存器的基地址
#define oNFCONT  0x04 //相对Nand配置寄存器基地址的偏移量，可得到控制寄存器的基地址(0x4E000004)

#define oNFADDR  0x0c //相对Nand配置寄存器基地址的偏移量，可得到地址寄存器的基地址(0x4E00000c)
#define oNFDATA  0x10 //相对Nand配置寄存器基地址的偏移量，可得到数据寄存器的基地址(0x4E000010)
#define oNFCMD   0x08 //相对Nand配置寄存器基地址的偏移量，可得到指令寄存器的基地址(0x4E000008)
#define oNFSTAT  0x20 //相对Nand配置寄存器基地址的偏移量，可得到状态寄存器的基地址(0x4E000020)

#define oNFECC   0x2c //相对Nand配置寄存器基地址的偏移量，可得到ECC寄存器的基地址(0x4E00002c)
 
#if defined(CONFIG_CMD_NAND)
#define CONFIG_NAND_S3C2410
#define CONFIG_SYS_NAND_BASE 0x4E000000 
#define CONFIG_SYS_MAX_NAND_DEVICE 1 /* Max number of NAND devices  */
#define SECTORSIZE 512
#define SECTORSIZE_2K 2048
#define NAND_SECTOR_SIZE SECTORSIZE
#define NAND_SECTOR_SIZE_2K SECTORSIZE_2K
#define NAND_BLOCK_MASK 511
#define NAND_BLOCK_MASK_2K 2047
#define NAND_MAX_CHIPS 1
#define CONFIG_MTD_NAND_VERIFY_WRITE 
#define CONFIG_SYS_64BIT_VSPRINTF  /* needed for nand_util.c */
#endif /* CONFIG_CMD_NAND */
#define CONFIG_JFFS2_NAND 1
//#undef CONFIG_JFFS2_CMDLINE
#define CONFIG_JFFS2_DEV "nand0"
#define CONFIG_JFFS2_PART_SIZE 0x480000
#define CONFIG_JFFS2_PART_OFFSET 0x80000
#define CONFIG_JFFS2_CMDLINE 1
#define MTDIDS_DEFAULT "nand0=nandflash0"
#define MTDPARTS_DEFAULT "mtdparts=nandflash0:384k(bootloader)," \
           "128k(params)," \
           "5m(kernel)," \
           "-(root)"
#define CONFIG_MTD_NAND_YAFFS2   1
#define ENABLE_CMD_LOADB_X 1
 
#endif	/* __CONFIG_H */
