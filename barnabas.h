#include <stdio.h>
#ifndef BARNABAS_H
#define BARNABAS_H
void binit();
void bquit();
void bwash();
void bsize(int *, int *);
void bread(char *, int, char *);
#define bputs(str) fputs(str, stderr)
#define bputc(chr) fputc(chr, stderr)
#endif
