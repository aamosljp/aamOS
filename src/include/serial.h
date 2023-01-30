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

#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <sys/types.h>

#define COM1 0x3f8
#define COM2 0x2f8
#define COM3 0x3e8
#define COM4 0x2e8

#define SERIAL_DATA 0						/* Data Register if DLAB = 0 | Baud Rate Divisor Least Significant Byte if DLAB = 1 */
#define SERIAL_INT_ENABLE 1					/* Interrupt Enable Register if DLAB = 0 | Baud Rate Divisor Most Significant Byte if DLAB = 1 */
#define SERIAL_INT_ID_FIFO_CONTROL 2		/* Interrupt Identification and FIFO Control Registers */
#define SERIAL_LINE_CONTROL 3				/* Line Control Register. Most Significant Bit = DLAB */
#define SERIAL_MODEM_CONTROL 4				/* Modem Control Register */
#define SERIAL_LINE_STATUS 5				/* Line Status Register */
#define SERIAL_MODEM_STATUS 6				/* Modem Status Register */
#define SERIAL_SCRATCH 7					/* Scratch Register */

void init_serial(uint16_t port);
uint8_t read_serial(void);
void write_serial(char a);
void write_serial_str(char* a);

#endif
