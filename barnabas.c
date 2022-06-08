#include <termios.h>
#include "barnabas.h"

static struct termios *old_settings() {
	static struct termios oldSettings;
	return &oldSettings;
}

void binit() {
	struct termios newSettings;
	tcgetattr(fileno(stdin), old_settings());
	newSettings = *old_settings();
	newSettings.c_lflag &= (~ICANON & ~ECHO);
	tcsetattr(fileno(stdin), TCSANOW, &newSettings);
	// Write to new screen, no line wrap, hide cursor, clear screen, go to 0,0
	fputs("\033[?1049h\033[?7l\033[?25l\033[2J\033[H", stdout);
}

void bquit() {
	// Line wrap, show cursor, write to old screen
	fputs("\033[?7h\033[?25h\033[?1049l", stdout);
	tcsetattr(fileno(stdin), TCSANOW, old_settings());
}
