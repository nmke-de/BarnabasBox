#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include "../Itoa/itoa.h"
#include "barnabas.h"

void bread(char *buf, int n, char *prompt) {
	struct winsize wsize;
	struct termios oldSettings, newSettings;
	char c;
	int goneleft = 0;
	tcgetattr(fileno(stdin), &oldSettings);
	newSettings = oldSettings;
	newSettings.c_lflag |= (ECHO|ICANON);
	tcsetattr(fileno(stdin), TCSANOW, &newSettings);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
	bputs("\033[s\033[");
	bputs(itoa(wsize.ws_row, 10));
	bputs(";1H\033[2K\033[?25h");
	bputs(prompt);
	fgets(buf, n, stdin);
	int tmplen = strlen(buf) - 1;
	if (buf[tmplen] == '\n') buf[tmplen] = 0;
	bputs("\033[A1\033[?25l\033[u");
	tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
}
