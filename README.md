# BarnabasBox

**BarnabasBox** is a bare-minimum TUI library. It is written with common Linux distributions in mind and while it may work on other operating systems, there is no guarantee for this.

![Screenshot showcasing an example application made with BarnabasBox](screenshot.png)

## But why?

Because I can. Also, statically linked binaries using [Termbox2](https://github.com/termbox/termbox2) are too large (a.k.a. bloat).

## What about the name?

> […] And Joses, who by the apostles was surnamed Barnabas, (which is, being interpreted, The son of consolation,) a Levite, and of the country of Cyprus […]

*Acts 4:36*

Barnabas is a cool name, period. Also, I didn't come up with a better name when I named my files.

## Dependencies

- libc (including an implementation of termios.h and stdio.h)
- terminal supporting ECMA-48
- C compiler (i.e. gcc or [cproc](https://github.com/michaelforney/cproc))

## Build

Type `make` if you have make installed. Edit the Makefile to suit your wishes.

Otherwise, you can compile each file manually with `CC -c -o name-of-file.o name-of-file.c`, where `CC` is your C compiler and `name-of-file` the file you want to compile.
After that, the command `ar -rc libbarnabas.a *.o` should yield a static library ready for use.

## Usage

```C
#include "barnabas.h"

int main() {
	// Initialize TUI
	binit();
	
	bputs("Hello, World!");
	fgetc(stdin);

	// Clear screen
	bwash();
	
	// Get terminal size
	int row, col;
	bsize(&row, &col);

	// Input prompt
	char str[64];
	bread(str, 64, "Type something here: ");
	bputs(str);

	fgetc(stdin);
	
	// Deinitialize TUI
	bquit();
}
```

For more examples, take a look [here](https://github.com/nmke-de/Examples4BarnabasBox) or [here](https://github.com/nmke-de/bar-menu)!
