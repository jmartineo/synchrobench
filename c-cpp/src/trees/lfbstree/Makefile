#VERSION = TCMALLOC_NO_UPDATE

ROOT = ../../..

include $(ROOT)/common/Makefile.common

.PHONY:	all clean
all:	main

BINS = $(BINDIR)/lockfree-bst

SHARED_LIB = $(BUILDIR)/liblfbstree.so

CC = g++
CFLAGS += -std=gnu++0x

main: test.o
	$(CC) $(CFLAGS) ${BUILDIR}/test.o -o $(BINS) $(LDFLAGS)

lib:
	$(CC) $(CFLAGS) -fPIC -c -o ${BUILDIR}/test.o test.c
	$(CC) -shared -o $(SHARED_LIB) ${BUILDIR}/test.o

test.o: wfrbt.h test.c
	$(CC) $(CFLAGS) -c -o ${BUILDIR}/test.o test.c
clean:
	-rm -f $(BINS) *.o
