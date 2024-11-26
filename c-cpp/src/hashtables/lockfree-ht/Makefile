ROOT = ../../..

include $(ROOT)/common/Makefile.common

ifeq ($(STM),SEQUENTIAL)
  BINS = $(BINDIR)/sequential-hashtable
else ifeq ($(STM),LOCKFREE)
  BINS = $(BINDIR)/lockfree-hashtable
else
  BINS = $(BINDIR)/$(STM)-hashtable
endif

SHARED_LIB = $(BUILDIR)/libhashtable.so 
LLREP = $(ROOT)/src/linkedlists/lockfree-list
CFLAGS += -std=gnu89

.PHONY:	all clean

all:	main

linkedlist.o:
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/linkedlist.o $(LLREP)/linkedlist.c

harris.o: $(LLREP)/linkedlist.h linkedlist.o
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/harris.o $(LLREP)/harris.c

ll-intset.o: $(LLREP)/linkedlist.h linkedlist.o harris.o
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/ll-intset.o $(LLREP)/intset.c

hashtable.o: $(LLREP)/linkedlist.h linkedlist.o harris.o ll-intset.o
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/hashtable.o hashtable.c

intset.o: $(LLREP)/linkedlist.h harris.o hashtable.o 
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/intset.o intset.c

test.o: linkedlist.o harris.o intset.o hashtable.o intset.o
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/test.o test.c

main: linkedlist.o harris.o intset.o hashtable.o intset.o test.o 
	$(CC) $(CFLAGS) $(BUILDIR)/linkedlist.o $(BUILDIR)/harris.o $(BUILDIR)/ll-intset.o $(BUILDIR)/hashtable.o $(BUILDIR)/intset.o $(BUILDIR)/test.o -o $(BINS) $(LDFLAGS)

# Build the shared library
lib: 
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/linkedlist.o $(LLREP)/linkedlist.c
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/harris.o $(LLREP)/harris.c
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/ll-intset.o $(LLREP)/intset.c
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/hashtable.o hashtable.c
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/intset.o intset.c
#	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/test.o test.c
	$(CC) -shared -o $(SHARED_LIB) $(BUILDIR)/linkedlist.o $(BUILDIR)/harris.o $(BUILDIR)/ll-intset.o $(BUILDIR)/hashtable.o $(BUILDIR)/intset.o # $(BUILDIR)/test.o

clean:
	-rm -f $(BINS)
