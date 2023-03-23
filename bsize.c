#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stddef.h>
#include "barnabas.h"

void bsize(int *row, int *col) {
	struct winsize wsize;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
	if (row != NULL)
		*row = wsize.ws_row;
	if (col != NULL)
		*col = wsize.ws_col;
}
