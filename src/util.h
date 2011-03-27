#ifndef _UTIL_H
#define _UTIL_H

// we are only going to support 32 bits right now

int redislitePutVarint32(unsigned char*, int);
int redisliteGetVarint32(const unsigned char *, int *);

#define getVarint32(A,B)  (int)((*(A)<(int)0x80) ? ((B) = (int)*(A)),1 : redisliteGetVarint32((A), (int *)&(B)))
#define putVarint32(A,B)  (int)(((int)(B)<(int)0x80) ? (*(A) = (unsigned char)(B)),1 : redislitePutVarint32((A), (B)))


void redislite_put_4bytes(unsigned char *p, int v);
int redislite_get_4bytes(const char *p);

#endif
