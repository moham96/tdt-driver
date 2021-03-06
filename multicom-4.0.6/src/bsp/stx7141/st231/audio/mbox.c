/**************************************************************
 * Copyright (C) 2010   STMicroelectronics. All Rights Reserved.
 * This file is part of the latest release of the Multicom4 project. This release 
 * is fully functional and provides all of the original MME functionality.This 
 * release  is now considered stable and ready for integration with other software 
 * components.

 * Multicom4 is a free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License as published by the Free Software Foundation 
 * version 2.

 * Multicom4 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with Multicom4; 
 * see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - 
 * Suite 330, Boston, MA 02111-1307, USA.

 * Written by Multicom team at STMicroelectronics in November 2010.  
 * Contact multicom.support@st.com. 
**************************************************************/

/* 
 * 
 */ 

#include <bsp/_bsp.h>

#define MBOX0_ADDR	0xfe211000
#define MBOX1_ADDR	0xfe212000
#define MBOX2_ADDR	0xfe211800
#define MBOX3_ADDR	0xfe212800

#include <os21/st200.h>

/* #include <os21/st200/sti7141.h> */
extern interrupt_name_t OS21_INTERRUPT_MAILBOX;

struct bsp_mbox_regs bsp_mailboxes[] =
{
  { 
    .base	= (void *) (MBOX0_ADDR), 		/* Video LX Mailbox (MBOX0.1) */
    .interrupt	= 0,
    .flags      = 0
  },
  { 
    .base	= (void *) (MBOX0_ADDR+0x100), 		/* Video LX Mailbox (MBOX0.2) */
    .interrupt	= 0,
    .flags      = 0
  },


#ifndef DISABLE_ESTB_ECM_MAILBOXES
  { 
    .base	= (void *) (MBOX2_ADDR), 		/* ST40 ECM Mailbox (MBOX2.1) */
    .interrupt	= 0,
    .flags      = 0
  },
  { 
    .base	= (void *) (MBOX2_ADDR+0x100), 		/* ST40 ECM Mailbox (MBOX2.2) */
    .interrupt	= 0,
    .flags      = 0
  },
#endif /* DISABLE_ESTB_ECM_MAILBOXES */


  { .base	= (void *) (MBOX1_ADDR),		/* Audio LX Mailbox (MBOX1.1) */
    .interrupt  = (unsigned int) &OS21_INTERRUPT_MAILBOX,/* *WE* own this one */
    .flags      = 0
  },
  { .base	= (void *) (MBOX1_ADDR+0x100),		/* Audio LX Mailbox (MBOX1.2) */
    .interrupt  = 0,
    .flags      = 0
  },

#ifndef DISABLE_ESTB_ECM_MAILBOXES
  { .base	= (void *) (MBOX3_ADDR),		/* ST40 ESTB Mailbox (MBOX3.1) */
    .interrupt  = 0,
    .flags      = 0
  },
  { .base	= (void *) (MBOX3_ADDR+0x100),		/* ST40 ESTB Mailbox (MBOX3.1) */
    .interrupt  = 0,
    .flags      = 0
  },
#endif /* DISABLE_ESTB_ECM_MAILBOXES */

};

unsigned int bsp_mailbox_count = sizeof(bsp_mailboxes)/sizeof(bsp_mailboxes[0]);

/*
 * Local Variables:
 *  tab-width: 8
 *  c-indent-level: 2
 *  c-basic-offset: 2
 * End:
 */
