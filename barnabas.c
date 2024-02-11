#include <termios.h>
#include "barnabas.h"

static struct termios *old_settings() {
	static struct termios oldSettings;
	return &oldSettings;
}

void binit() {
	struct termios newSettings;
	tcgetattr(STDIN_FILENO, old_settings());
	newSettings = *old_settings();
	newSettings.c_lflag &= (~ICANON & ~ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
	// Write to new screen, no line wrap, hide cursor, clear screen, go to 0,0
	bputs("\033[?1049h\033[?7l\033[?25l\033[2J\033[H");
}

void bquit() {
	// Line wrap, show cursor, write to old screen
	bputs("\033[?7h\033[?25h\033[?1049l");
	tcsetattr(STDIN_FILENO, TCSANOW, old_settings());
}
