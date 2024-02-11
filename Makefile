

build: object-files
	ar -rc libbarnabas.a *.o Itoa/itoa.o print/libprint.a

object-files: barnabas.o bread.o bsize.o clear.o Itoa-Submodule print-Submodule

barnabas.o: barnabas.c barnabas.h
	$(CC) -c -o barnabas.o barnabas.c print/print.h

bread.o: bread.c barnabas.h Itoa/itoa.h
	$(CC) -c -o bread.o bread.c print/print.h

bsize.o: bsize.c barnabas.h
	$(CC) -c -o bsize.o bsize.c

clear.o: clear.c barnabas.h
	$(CC) -c -o clear.o clear.c print/print.h

Itoa-Submodule: Itoa/
	make -C Itoa -f Makefile

print-Submodule: print/
	make -C print -f Makefile

clean:
	rm -f *.o
	rm -f Itoa/*.o
	rm -f libbarnabas.a

all: build clean

