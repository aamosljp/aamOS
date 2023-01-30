/*******************************************************************************************
 * This file is part of aamOS.
 *
 * aamOS is free software: you can redistribute it and/or modify it under the
 *terms of the GNU General Public License as published by the Free Software
 *Foundation, either version 3 of the License, or (at your option) any later
 *version.
 *
 * aamOS is distributed in the hope that it will be useful, but WITHOUT ANY
 *WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 *A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 *aamOS. If not, see <https://www.gnu.org/licenses/>.
 *******************************************************************************************/
#include <printf.h>
#include <stdarg.h>

int __printf(const char *format, ...) {
  va_list arg;
  int done;

  va_start(arg, format);
  done = __vsprintf(printbuf, format, arg);
  va_end(arg);

  return done;
}
extern __typeof(__printf) printf __attribute__((alias("__printf")));
