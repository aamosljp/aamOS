/*******************************************************************************************
 * This file is part of aamOS.
 *
 * aamOS is free software: you can redistribute it and/or modify it under the terms of the 
 * GNU General Public License as published by the Free Software Foundation, either version 3 
 * of the License, or (at your option) any later version.
 *
 * aamOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with aamOS. 
 * If not, see <https://www.gnu.org/licenses/>.
 *******************************************************************************************/

#ifndef _ISR_H
#define _ISR_H

#include <sys/types.h>

typedef struct registers
{
	uint32_t ds;					                    /* Data segment selector */
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; 	/* Pushed by pusha. */
	uint32_t int_no, err_code;			                /* Interrupt number and error code (if applicable) */
	uint32_t eip, cs, eflags, useresp, ss;		        /* Pushed by the processor automatically. */
} registers_t;
typedef void (*isr_t)(registers_t);

struct IDT_entry {
	unsigned short int offset_lo;   /* The lowest 16 bits of the offset */
	unsigned short int selector;    /**/
	unsigned char zero;             /* Always zero */
	unsigned char type_attr;        /* Type of interrupt */
	unsigned short int offset_hi;   /* The highest 16 bits of the offset */
};

void idt_init(void);

void irq0_handler(void);
void irq1_handler(void);
void irq2_handler(void);
void irq3_handler(void);
void irq4_handler(void);
void irq5_handler(void);
void irq6_handler(void);
void irq7_handler(void);
void irq8_handler(void);
void irq9_handler(void);
void irq10_handler(void);
void irq11_handler(void);
void irq12_handler(void);
void irq13_handler(void);
void irq14_handler(void);
void irq15_handler(void);

#endif
