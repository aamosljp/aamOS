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

#ifndef _VGA_H_
#define _VGA_H_

#include <sys/types.h>

#define WHITE 0xffffff
#define LIGHT_GRAY 0xc0c0c0
#define DARK_GRAY 0x808080
#define BLACK 0x000000
#define RED 0xff0000
#define DARK_RED 0x800000
#define YELLOW 0xffff00
#define BROWN 0x808000
#define GREEN 0x00ff00
#define DARK_GREEN 0x008000
#define CYAN 0x00ffff
#define DARK_CYAN 0x008080
#define BLUE 0x0000ff
#define DARK_BLUE 0x000080
#define MAGENTA 0xff00ff
#define PURPLE 0x800080



void VGA_init(struct multiboot_tag_framebuffer *tag);
void VGA_putpixel(uint32_t x, uint32_t y, uint32_t color);
void VGA_drawrect(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t color);
void VGA_drawchar(uint32_t x, uint32_t y, uint32_t c, uint32_t fg_color, uint32_t bg_color);
void VGA_print(uint32_t x, uint32_t y, uint8_t* s, uint32_t fg_color, uint32_t bg_color);
void VGA_scroll(char d);
uint32_t VGA_getpixel(uint32_t x, uint32_t y);
void VGA_clear(void);

#endif
