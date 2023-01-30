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
#include <aamOS/kernel.h>
#include <asm/io.h>

void set_timer_freq(int hz) {
	int d = 1193180 / hz;
	outb(0x43, 0x36);
	outb(0x40, d & 0xFF);
	outb(0x40, d >> 8);
}

void timer() {
  //write_serial('1');
}
