
CC = cproc

build: object-files
	ar -rc libbarnabas.a *.o

object-files: barnabas.o bread.o bsize.o clear.o

barnabas.o: barnabas.c barnabas.h
	$(CC) -c -o barnabas.o barnabas.c

bread.o: bread.c barnabas.h
	$(CC) -c -o bread.o bread.c

bsize.o: bsize.c barnabas.h
	$(CC) -c -o bsize.o bsize.c

clear.o: clear.c barnabas.h
	$(CC) -c -o clear.o clear.c

clean:
	rm -f *.o
	rm -f libbarnabas.a

all: build clean

