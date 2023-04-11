#include <printf.h>
#include <stdarg.h>
#include <serial.h>

extern char printbuf[1024];

int kprintf(const char *format, ...) {
  va_list arg;
  int done;

  va_start(arg, format);
  done = __vsprintf(printbuf, format, arg);
  va_end(arg);

  write_serial_str(printbuf);
  return done;
}
