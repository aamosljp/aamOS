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
#include <sys/types.h>
#include <utils.h>
#include <stdarg.h>

/* Convert the integer D to a string and save the string in BUF. If
 BASE is equal to ’d’, interpret that D is decimal, and if BASE is
 equal to ’x’, interpret that D is hexadecimal. */
void itoa(char *buf, int base, int d) {
	char *p = buf;
	char *p1, *p2;
	unsigned long ud = (unsigned) d;
	int divisor = 10;

	/* If %d is specified and D is minus, put ‘-’ in the head. */
	if (base == 'd' && d < 0) {
		*p++ = '-';
		buf++;
		ud = (unsigned) -d;
	} else if (base == 'x') {
		divisor = 16;
	} else if (base == 'b') {
		divisor = 2;
	}
	/* Divide UD by DIVISOR until UD == 0. */
	do {
		uint32_t remainder = ud % (unsigned) divisor;

		*p++ =
				(char) ((remainder < 10) ?
						remainder + '0' : remainder + 'a' - 10);
	} while (ud /= (unsigned) divisor);

	/* Terminate BUF. */
	*p = 0;

	/* Reverse BUF. */
	p1 = buf;
	p2 = p - 1;
	while (p1 < p2) {
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}
}
