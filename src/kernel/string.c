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
#include <string.h>
#include <sys/types.h>
//
//char *strcpy (char *dest, const char *src)
//{
//  return memcpy (dest, src, strlen (src) + 1);
//}
//
//char *strncpy (char *s1, const char *s2, size_t n)
//{
//  size_t size = __strnlen (s2, n);
//  if (size != n)
//    memset (s1 + size, '\0', n - size);
//  return memcpy (s1, s2, size);
//}
//
//char *strcat (char *dest, const char *src)
//{
//  strcpy (dest + strlen (dest), src);
//  return dest;
//}
//
//char *strncat (char *s1, const char *s2, size_t n)
//{
//  char *s = s1;
//
//  /* Find the end of S1.  */
//  s1 += strlen (s1);
//
//  size_t ss = __strnlen (s2, n);
//
//  s1[ss] = '\0';
//  memcpy (s1, s2, ss);
//
//  return s;
//}
//
//int strcmp (const char *p1, const char *p2)
//{
//  const unsigned char *s1 = (const unsigned char *) p1;
//  const unsigned char *s2 = (const unsigned char *) p2;
//  unsigned char c1, c2;
//
//  do
//    {
//      c1 = (unsigned char) *s1++;
//      c2 = (unsigned char) *s2++;
//      if (c1 == '\0')
//	return c1 - c2;
//    }
//  while (c1 == c2);
//
//  return c1 - c2;
//}
//
//int strncmp (const char *s1, const char *s2, size_t n)
//{
//  unsigned char c1 = '\0';
//  unsigned char c2 = '\0';
//
//  if (n >= 4)
//    {
//      size_t n4 = n >> 2;
//      do
//	{
//	  c1 = (unsigned char) *s1++;
//	  c2 = (unsigned char) *s2++;
//	  if (c1 == '\0' || c1 != c2)
//	    return c1 - c2;
//	  c1 = (unsigned char) *s1++;
//	  c2 = (unsigned char) *s2++;
//	  if (c1 == '\0' || c1 != c2)
//	    return c1 - c2;
//	  c1 = (unsigned char) *s1++;
//	  c2 = (unsigned char) *s2++;
//	  if (c1 == '\0' || c1 != c2)
//	    return c1 - c2;
//	  c1 = (unsigned char) *s1++;
//	  c2 = (unsigned char) *s2++;
//	  if (c1 == '\0' || c1 != c2)
//	    return c1 - c2;
//	} while (--n4 > 0);
//      n &= 3;
//    }
//
//  while (n > 0)
//    {
//      c1 = (unsigned char) *s1++;
//      c2 = (unsigned char) *s2++;
//      if (c1 == '\0' || c1 != c2)
//	return c1 - c2;
//      n--;
//    }
//
//  return c1 - c2;
//}
//
//char *strchr (const char *s, int c_in)
//{
//  const unsigned char *char_ptr;
//  const unsigned long int *longword_ptr;
//  unsigned long int longword, magic_bits, charmask;
//  unsigned char c;
//
//  c = (unsigned char) c_in;
//
//  /* Handle the first few characters by reading one character at a time.
//     Do this until CHAR_PTR is aligned on a longword boundary.  */
//  for (char_ptr = (const unsigned char *) s;
//       ((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0;
//       ++char_ptr)
//    if (*char_ptr == c)
//      return (void *) char_ptr;
//    else if (*char_ptr == '\0')
//      return NULL;
//
//  /* All these elucidatory comments refer to 4-byte longwords,
//     but the theory applies equally well to 8-byte longwords.  */
//
//  longword_ptr = (unsigned long int *) char_ptr;
//
//  /* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
//     the "holes."  Note that there is a hole just to the left of
//     each byte, with an extra at the end:
//
//     bits:  01111110 11111110 11111110 11111111
//     bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
//
//     The 1-bits make sure that carries propagate to the next 0-bit.
//     The 0-bits provide holes for carries to fall into.  */
//  magic_bits = -1;
//  magic_bits = magic_bits / 0xff * 0xfe << 1 >> 1 | 1;
//
//  /* Set up a longword, each of whose bytes is C.  */
//  charmask = c | (c << 8);
//  charmask |= charmask << 16;
//  if (sizeof (longword) > 4)
//    /* Do the shift in two steps to avoid a warning if long has 32 bits.  */
//    charmask |= (charmask << 16) << 16;
//  if (sizeof (longword) > 8)
//    abort ();
//
//  /* Instead of the traditional loop which tests each character,
//     we will test a longword at a time.  The tricky part is testing
//     if *any of the four* bytes in the longword in question are zero.  */
//  for (;;)
//    {
//      /* We tentatively exit the loop if adding MAGIC_BITS to
//	 LONGWORD fails to change any of the hole bits of LONGWORD.
//
//	 1) Is this safe?  Will it catch all the zero bytes?
//	 Suppose there is a byte with all zeros.  Any carry bits
//	 propagating from its left will fall into the hole at its
//	 least significant bit and stop.  Since there will be no
//	 carry from its most significant bit, the LSB of the
//	 byte to the left will be unchanged, and the zero will be
//	 detected.
//
//	 2) Is this worthwhile?  Will it ignore everything except
//	 zero bytes?  Suppose every byte of LONGWORD has a bit set
//	 somewhere.  There will be a carry into bit 8.  If bit 8
//	 is set, this will carry into bit 16.  If bit 8 is clear,
//	 one of bits 9-15 must be set, so there will be a carry
//	 into bit 16.  Similarly, there will be a carry into bit
//	 24.  If one of bits 24-30 is set, there will be a carry
//	 into bit 31, so all of the hole bits will be changed.
//
//	 The one misfire occurs when bits 24-30 are clear and bit
//	 31 is set; in this case, the hole at bit 31 is not
//	 changed.  If we had access to the processor carry flag,
//	 we could close this loophole by putting the fourth hole
//	 at bit 32!
//
//	 So it ignores everything except 128's, when they're aligned
//	 properly.
//
//	 3) But wait!  Aren't we looking for C as well as zero?
//	 Good point.  So what we do is XOR LONGWORD with a longword,
//	 each of whose bytes is C.  This turns each byte that is C
//	 into a zero.  */
//
//      longword = *longword_ptr++;
//
//      /* Add MAGIC_BITS to LONGWORD.  */
//      if ((((longword + magic_bits)
//
//	    /* Set those bits that were unchanged by the addition.  */
//	    ^ ~longword)
//
//	   /* Look at only the hole bits.  If any of the hole bits
//	      are unchanged, most likely one of the bytes was a
//	      zero.  */
//	   & ~magic_bits) != 0
//
//	  /* That caught zeroes.  Now test for C.  */
//	  || ((((longword ^ charmask) + magic_bits) ^ ~(longword ^ charmask))
//	      & ~magic_bits) != 0)
//	{
//	  /* Which of the bytes was C or zero?
//	     If none of them were, it was a misfire; continue the search.  */
//
//	  const unsigned char *cp = (const unsigned char *) (longword_ptr - 1);
//
//	  if (*cp == c)
//	    return (char *) cp;
//	  else if (*cp == '\0')
//	    return NULL;
//	  if (*++cp == c)
//	    return (char *) cp;
//	  else if (*cp == '\0')
//	    return NULL;
//	  if (*++cp == c)
//	    return (char *) cp;
//	  else if (*cp == '\0')
//	    return NULL;
//	  if (*++cp == c)
//	    return (char *) cp;
//	  else if (*cp == '\0')
//	    return NULL;
//	  if (sizeof (longword) > 4)
//	    {
//	      if (*++cp == c)
//		return (char *) cp;
//	      else if (*cp == '\0')
//		return NULL;
//	      if (*++cp == c)
//		return (char *) cp;
//	      else if (*cp == '\0')
//		return NULL;
//	      if (*++cp == c)
//		return (char *) cp;
//	      else if (*cp == '\0')
//		return NULL;
//	      if (*++cp == c)
//		return (char *) cp;
//	      else if (*cp == '\0')
//		return NULL;
//	    }
//	}
//    }
//
//  return NULL;
//}
//
//char *strrchr (const char *s, int c)
//{
//  const char *found, *p;
//
//  c = (unsigned char) c;
//
//  /* Since strchr is fast, we use it rather than the obvious loop.  */
//
//  if (c == '\0')
//    return strchr (s, '\0');
//
//  found = NULL;
//  while ((p = strchr (s, c)) != NULL)
//    {
//      found = p;
//      s = p + 1;
//    }
//
//  return (char *) found;
//}

size_t strlen (const char *str)
{
  const char *char_ptr;
  const unsigned long int *longword_ptr;
  unsigned long int longword, himagic, lomagic;

  /* Handle the first few characters by reading one character at a time.
     Do this until CHAR_PTR is aligned on a longword boundary.  */
  for (char_ptr = str; ((unsigned long int) char_ptr
			& (sizeof (longword) - 1)) != 0;
       ++char_ptr)
    if (*char_ptr == '\0')
      return char_ptr - str;

  /* All these elucidatory comments refer to 4-byte longwords,
     but the theory applies equally well to 8-byte longwords.  */

  longword_ptr = (unsigned long int *) char_ptr;

  /* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
     the "holes."  Note that there is a hole just to the left of
     each byte, with an extra at the end:

     bits:  01111110 11111110 11111110 11111111
     bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD

     The 1-bits make sure that carries propagate to the next 0-bit.
     The 0-bits provide holes for carries to fall into.  */
  himagic = 0x80808080L;
  lomagic = 0x01010101L;
  if (sizeof (longword) > 4)
    {
      /* 64-bit version of the magic.  */
      /* Do the shift in two steps to avoid a warning if long has 32 bits.  */
      himagic = ((himagic << 16) << 16) | himagic;
      lomagic = ((lomagic << 16) << 16) | lomagic;
    }
  if (sizeof (longword) > 8)
    //abort ();
	  return -1;
  /* Instead of the traditional loop which tests each character,
     we will test a longword at a time.  The tricky part is testing
     if *any of the four* bytes in the longword in question are zero.  */
  for (;;)
    {
      longword = *longword_ptr++;

      if (((longword - lomagic) & ~longword & himagic) != 0)
	{
	  /* Which of the bytes was the zero?  If none of them were, it was
	     a misfire; continue the search.  */

	  const char *cp = (const char *) (longword_ptr - 1);

	  if (cp[0] == 0)
	    return cp - str;
	  if (cp[1] == 0)
	    return cp - str + 1;
	  if (cp[2] == 0)
	    return cp - str + 2;
	  if (cp[3] == 0)
	    return cp - str + 3;
	  if (sizeof (longword) > 4)
	    {
	      if (cp[4] == 0)
		return cp - str + 4;
	      if (cp[5] == 0)
		return cp - str + 5;
	      if (cp[6] == 0)
		return cp - str + 6;
	      if (cp[7] == 0)
		return cp - str + 7;
	    }
	}
    }
}
