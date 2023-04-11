#include <aamOS/kprintf.h>
#include <memory.h>
#include <serial.h>
#include <stdio.h>

extern char printbuf[1024];

uint32_t memoryEnd = 0x0;
struct reservedArea {
  uint32_t addr;
  uint32_t len;
} areasToReserve[256];
uint32_t areasNumber = 0;

int init_mmap(struct multiboot_tag_mmap *tag) {
  if (tag->type != 6)
    return -1;
  multiboot_memory_map_t *mmap;
  struct multiboot_tag_mmap *mmapTag = (struct multiboot_tag_mmap *)tag;

  for (mmap = mmapTag->entries;
       (multiboot_uint8_t *)mmap < (multiboot_uint8_t *)tag + tag->size;
       mmap = (multiboot_memory_map_t *)((unsigned long)mmap +
                                         mmapTag->entry_size)) {
    kprintf("Addr: %x | Length: %x | Type: %x | Zero: %x\n",
            (unsigned)(mmap->addr), (unsigned)(mmap->len), (unsigned)mmap->type,
            (unsigned)mmap->zero);

    memoryEnd += (uint32_t)mmap->len;

    if (mmap->type == MULTIBOOT_MEMORY_RESERVED) {
      areasToReserve[areasNumber].addr = mmap->addr;
      areasToReserve[areasNumber].len = mmap->len;
      kprintf("%x %x\n", areasToReserve[areasNumber].addr,
              areasToReserve[areasNumber].len);
      areasNumber++;
    }
  }
  return memoryEnd;
}
