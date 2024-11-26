ROOT = ../../..

include $(ROOT)/common/Makefile.common

SHARED_LIB = $(BUILDIR)/liblinkedlist-harris.so

ifeq ($(STM),SEQUENTIAL)
  BINS = $(BINDIR)/sequential-linkedlist
else ifeq ($(STM),LOCKFREE)
  BINS = $(BINDIR)/lockfree-linkedlist
else
  BINS = $(BINDIR)/$(STM)-linkedlist
endif
CFLAGS += -std=gnu89

.PHONY:	all clean

all:	main

linkedlist.o:
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/linkedlist.o linkedlist.c

harris.o: linkedlist.h linkedlist.o
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/harris.o harris.c

intset.o: linkedlist.h harris.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/intset.o intset.c

test.o: linkedlist.h harris.h intset.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/test.o test.c

main: linkedlist.o harris.o intset.o test.o $(TMILB)
	$(CC) $(CFLAGS) $(BUILDIR)/linkedlist.o $(BUILDIR)/harris.o $(BUILDIR)/intset.o $(BUILDIR)/test.o -o $(BINS) $(LDFLAGS)

lib: 
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/linkedlist.o linkedlist.c
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/harris.o harris.c
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/intset.o intset.c
	$(CC) -shared -o $(SHARED_LIB) $(BUILDIR)/linkedlist.o $(BUILDIR)/harris.o $(BUILDIR)/intset.o

clean:
	-rm -f $(BINS)
