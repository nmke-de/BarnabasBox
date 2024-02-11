#include "print/print.h"
#ifndef BARNABAS_H
#define BARNABAS_H
void binit();
void bquit();
void bwash();
void bsize(int *, int *);
void bread(char *, int, char *);
#define bputs(...) logv(__VA_ARGS__)
#define bputc(chr) write(2, (&chr), 1)
#endif
