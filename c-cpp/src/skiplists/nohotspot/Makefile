ROOT = ../../..

include $(ROOT)/common/Makefile.common

BINS = $(BINDIR)/lockfree-nohotspot-skiplist

SHARED_LIB = $(BUILDIR)/libnohotspot-skiplist.so

.PHONY:	all clean

all:	main

ptst.o: ptst.h 
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/ptst.o ptst.c -I.

garbagecoll.o: garbagecoll.h ptst.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/garbagecoll.o garbagecoll.c -I.

nohotspot_ops.o: skiplist.h background.h nohotspot_ops.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/nohotspot_ops.o nohotspot_ops.c -I.

skiplist.o: skiplist.h background.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/skiplist.o skiplist.c -I.

background.o: background.h skiplist.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/background.o background.c -I.

intset.o: intset.h nohotspot_ops.h skiplist.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/intset.o intset.c -I.

test.o: intset.h
	$(CC) $(CFLAGS) -c -o $(BUILDIR)/test.o test.c -I.

main: intset.o background.o skiplist.o nohotspot_ops.o test.o ptst.o garbagecoll.o
	$(CC) $(CFLAGS) $(BUILDIR)/garbagecoll.o $(BUILDIR)/ptst.o $(BUILDIR)/skiplist.o $(BUILDIR)/nohotspot_ops.o $(BUILDIR)/intset.o $(BUILDIR)/background.o $(BUILDIR)/test.o -o $(BINS) $(LDFLAGS)

lib:
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/ptst.o ptst.c -I.
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/garbagecoll.o garbagecoll.c -I.
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/nohotspot_ops.o nohotspot_ops.c -I.
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/skiplist.o skiplist.c -I.
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/background.o background.c -I.
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/intset.o intset.c -I.
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/test.o test.c -I.
	$(CC) -shared -o $(SHARED_LIB) $(BUILDIR)/ptst.o $(BUILDIR)/garbagecoll.o $(BUILDIR)/nohotspot_ops.o $(BUILDIR)/skiplist.o $(BUILDIR)/background.o $(BUILDIR)/intset.o $(BUILDIR)/test.o

clean:
	-rm -f $(BINS)
