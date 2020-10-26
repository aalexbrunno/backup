/* See comments below */

const unsigned char data[] = {
/* 000000 */  0x2f,  0x2a,  0x20,  0x54,  0x68,  0x69,  0x73,  0x20,
/* 0x0008 */  0x69,  0x73,  0x20,  0x61,  0x20,  0x73,  0x65,  0x6c,
/* 0x0010 */  0x66,  0x72,  0x65,  0x70,  0x20,  0x28,  0x71,  0x75,
/* 0x0018 */  0x69,  0x6e,  0x65,  0x29,  0x20,  0x70,  0x72,  0x6f,
/* Several lines snipped.  See the original file for a complete listing. */
/* 0x02c0 */  0x20,  0x28,  0x64,  0x61,  0x74,  0x61,  0x5b,  0x69,
/* 0x02c8 */  0x5d,  0x29,  0x3b,  0x0a,  0x20,  0x20,  0x72,  0x65,
/* 0x02d0 */  0x74,  0x75,  0x72,  0x6e,  0x20,  0x30,  0x3b,  0x0a,
/* 0x02d8 */  0x7d,  0x0a,
};

/* This is a selfrep (quine) program.  It uses the above data (which
 * is no other than the ASCII representation of everything starting
 * from this comment) to print its own listing. */

#include <stdio.h>

int
main (void)
     /* The main program.  We output the data in the format used at
      * the top of this file, and then we use it to generate the rest
      * of this file. */
{
  unsigned int i;

  printf ("/* See comments below */\n\n");
  printf ("const unsigned char data[] = {");
  for ( i=0 ; i<sizeof(data) ; i++ )
    {
      if ( i%8 == 0 )
	printf ("\n/* %0#6x */",i);
      printf ("  %0#4x,", data[i]);
    }
  printf ("\n};\n\n");
  for ( i=0 ; i<sizeof(data) ; i++ )
    putchar (data[i]);
  return 0;
}
