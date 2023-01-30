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
#include <asm/io.h>
#include <stdio.h>
#include <time.h>

#define CMOS_READ(reg)                                                         \
  ({                                                                           \
    outb_p(0x70, 0x80 | reg);                                                  \
    inb_p(0x71);                                                               \
  })

#define BCD_TO_BIN(val) ((val) = ((val)&15) + ((val) >> 4) * 10)

#define MINUTE 60
#define HOUR (60 * MINUTE)
#define DAY (24 * HOUR)
#define YEAR (365 * DAY)

const char *weekdays[7] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                           "Friday", "Saturday", "Sunday"};

static int month[12] = {
    0,
    DAY * (31),
    DAY * (31 + 29),
    DAY * (31 + 29 + 31),
    DAY * (31 + 29 + 31 + 30),
    DAY * (31 + 29 + 31 + 30 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)};

long startup_time;

long mktime(struct tm *tm) {
  long res;
  int year;

  year = tm->tm_year - 70;
  /* magic offsets (y+1) needed to get leapyears right.*/
  res = YEAR * year + DAY * ((year + 1) / 4);
  res += month[tm->tm_mon];
  /* and (y+2) here. If it wasn't a leap-year, we have to adjust */
  if (tm->tm_mon > 1 && ((year + 2) % 4))
    res -= DAY;
  res += DAY * (tm->tm_mday - 1);
  res += HOUR * tm->tm_hour;
  res += MINUTE * tm->tm_min;
  res += tm->tm_sec;
  return res;
}

struct tm get_time() {
  struct tm time;

  do {
    time.tm_sec = CMOS_READ(0);
    time.tm_min = CMOS_READ(2);
    time.tm_hour = CMOS_READ(4);
    time.tm_mday = CMOS_READ(7);
    time.tm_mon = CMOS_READ(8) - 1;
    time.tm_year = CMOS_READ(9);
  } while (time.tm_sec != CMOS_READ(0));
  BCD_TO_BIN(time.tm_sec);
  BCD_TO_BIN(time.tm_min);
  BCD_TO_BIN(time.tm_hour);
  BCD_TO_BIN(time.tm_mday);
  BCD_TO_BIN(time.tm_mon);
  BCD_TO_BIN(time.tm_year);
  return time;
}

void time_init() {
  struct tm time = get_time();
  startup_time = mktime(&time);
}
