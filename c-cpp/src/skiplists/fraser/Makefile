ROOT = ../../..

include $(ROOT)/common/Makefile.common

BINS = $(BINDIR)/lockfree-fraser-skiplist

DEBUGGING := -DNDEBUG
INCLUDE   := -I../../include/

#ARCH      := SPARC
ifneq ($(ARCH_NAME), sun4v)
    ARCH = INTEL
else 
    ARCH = SPARC
endif

CFLAGS      += -D$(ARCH) -Wno-unused-value -Wno-format #-fomit-frame-pointer

SHARED_LIB = $(BUILDIR)/libfraser-skiplist.so

#CFLAGS      += $(DEBUGGING)
COMMON_DEPS += Makefile $(wildcard *.h)

GC_HARNESS_TARGETS := skip_lock_perlist skip_lock_pernode skip_lock_perpointer
GC_HARNESS_TARGETS += skip_cas skip_mcas

GC_HARNESS_TARGETS += bst_lock_fraser bst_lock_manber bst_lock_kung
GC_HARNESS_TARGETS += bst_mcas

GC_HARNESS_TARGETS += rb_lock_concurrentwriters rb_lock_serialisedwriters
GC_HARNESS_TARGETS += rb_lock_mutex

TARGETS    := $(GC_HARNESS_TARGETS)
TARGETS    += rb_stm_fraser rb_stm_herlihy rb_stm_lock
TARGETS    += skip_stm_fraser skip_stm_herlihy skip_stm_lock

all: main cleanbuild

main: intset.o ptst.h set.h skip_cas.o gc.o ptst.o portable_defns.h sparc_defns.h intel_defns.h intset.h
	$(CC) $(CFLAGS) intset.o gc.o ptst.o skip_cas.o test.c -o $(BINS) $(LDFLAGS)

lib:
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/ptst.o ptst.c $(INCLUDE)
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/gc.o gc.c $(INCLUDE)
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/skip_cas.o skip_cas.c $(INCLUDE)
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/intset.o intset.c $(INCLUDE)
	$(CC) $(CFLAGS) -fPIC -c -o $(BUILDIR)/test.o test.c $(INCLUDE)
	$(CC) -shared -o $(SHARED_LIB) $(BUILDIR)/ptst.o $(BUILDIR)/gc.o $(BUILDIR)/skip_cas.o $(BUILDIR)/intset.o $(BUILDIR)/test.o


cleanbuild:
	rm -f *~ core *.o *.a

clean:
	rm -f *~ core *.o *.a
	rm -f $(BINS)

%.o: %.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(GC_HARNESS_TARGETS): %: %.o set_harness.o ptst.o gc.o
	$(CC) -o $@ $^ $(LDFLAGS)
