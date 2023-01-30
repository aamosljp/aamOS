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

#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>

extern int vsprintf(char *buf, const char *fmt, va_list args);
extern int vprintf(const char *format, va_list args);
extern int sprintf(char *s, const char *format, ...);
extern int printf(const char *format, ...);

#endif
