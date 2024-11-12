ROOT = ../../..

include $(ROOT)/common/Makefile.common

ifeq ($(STM),SEQUENTIAL)
  BINS = $(BINDIR)/sequential-linkedlist
else ifeq ($(STM),LOCKFREE)
  BINS = $(BINDIR)/lockfree-linkedlist
else
  BINS = $(BINDIR)/$(STM)-linkedlist
endif

CFLAGS += -Wall -pedantic -std=gnu11
#LDFLAGS += -ltcmalloc

SHARED_LIB_FOMITCHEV = $(BUILDIR)/liblinkedlist-fomitchev.so
SHARED_LIB_SELFISH = $(BUILDIR)/liblinkedlist-selfish.so


.PHONY:	all clean

all: selfish fomitchev

selfish.o:
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/selfish.o selfish.c

selfish: selfish.o test.c
	$(CC) $(CFLAGS) -DSELFISH $(BUILDIR)/selfish.o test.c -o $(BINDIR)/lockfree-selfishlist $(LDFLAGS)

fomitchev.o:
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/fomitchev.o fomitchev.c

fomitchev: fomitchev.o test.c
	$(CC) $(CFLAGS) -DFOMITCHEV $(BUILDIR)/fomitchev.o test.c -o $(BINDIR)/lockfree-fomitchevlist $(LDFLAGS)

lib: 
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/fomitchev.o fomitchev.c
	$(CC) -shared -o $(SHARED_LIB_FOMITCHEV) $(BUILDIR)/fomitchev.o
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/selfish.o selfish.c
	$(CC) -shared -o $(SHARED_LIB_SELFISH) $(BUILDIR)/selfish.o

clean:	
	-rm -f *.o $(BINS)
