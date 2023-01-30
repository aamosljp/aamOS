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
#include <aamOS/kernel.h>
#include <asm/io.h>
#include <asm/system.h>
#include <console.h>
#include <keyboard.h>
#include <multiboot2.h>
#include <serial.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <utils.h>
#include <vga.h>
#include <memory.h>

extern char printbuf[1024];
extern char *weekdays[7];
extern long startup_time;
extern void idt_init(void);
extern void loadGdt(void);
struct multiboot_tag *get_tag(uint32_t tag_type, unsigned long addr);
void kernel_main(unsigned long magic, unsigned long addr);

void kernel_main(unsigned long magic, unsigned long addr) {
  init_serial(COM1);
  struct multiboot_tag *tag;
  write_serial_str("Checking bootloader magic number...\n");
  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
    write_serial_str("Invalid magic number!\n");
    iret();
  }
  write_serial_str("Loading memory map...\n");
  tag = get_tag(MULTIBOOT_TAG_TYPE_MMAP, addr);
  if(init_mmap((struct multiboot_tag_mmap *)tag) == -1) {
      write_serial_str("Invalid memory map given by GRUB!\n");
      iret();
  }
  tag = get_tag(MULTIBOOT_TAG_TYPE_FRAMEBUFFER, addr);
  VGA_init((struct multiboot_tag_framebuffer *)tag);
  console_init((struct multiboot_tag_framebuffer *)tag, WHITE, BLACK);
  loadGdt();
  idt_init();
  sti();
  kb_init();
  time_init();
}

struct multiboot_tag *get_tag(uint32_t tag_type, unsigned long addr) {
  struct multiboot_tag *tag;
  for (tag = (struct multiboot_tag *)(addr + 8);
       tag->type != MULTIBOOT_TAG_TYPE_END;
       tag = (struct multiboot_tag *)((multiboot_uint8_t *)tag +
                                      ((tag->size + 7) & ~7))) {
    if (tag->type == tag_type) {
      break;
    }
  }
  return tag;
}
