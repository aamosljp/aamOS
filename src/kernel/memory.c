#include <memory.h>
#include <serial.h>
#include <stdio.h>

extern char printbuf[1024];

int init_mmap(struct multiboot_tag_mmap *mmap) {
  if (mmap->type != 6)
    return -1;
  unsigned int i;
  for (i = 0; i < mmap->size; i += mmap->entry_size) {
    struct multiboot_mmap_entry *mme = mmap->entries + i;
    printf("Start Addr: %x | Length: %x | Type: %x | Zero: %x\n", mme->addr,
           mme->len, mme->type, mme->zero);
    write_serial_str(printbuf);
  }
  return mmap->size;
}
