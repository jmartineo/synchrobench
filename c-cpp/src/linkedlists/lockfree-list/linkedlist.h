/*
 *  linkedlist.h
 *  
 *
 *  Created by Vincent Gramoli on 1/12/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

#include <atomic_ops.h>

#include "tm.h"

#ifdef DEBUG
#define IO_FLUSH                        fflush(NULL)
/* Note: stdio is thread-safe */
#endif

#define ATOMIC_CAS_MB(a, e, v)          (AO_compare_and_swap_full((volatile AO_t *)(a), (AO_t)(e), (AO_t)(v)))

#define TRANSACTIONAL                   d->unit_tx

typedef intptr_t val_t;
#define VAL_MIN                         INT_MIN
#define VAL_MAX                         INT_MAX

typedef struct node {
	val_t val;
	struct node *next;
} node_t;

typedef struct intset {
	node_t *head;
} intset_t;

node_t *new_node(val_t val, node_t *next, int transactional);
intset_t *set_new();
void set_delete(intset_t *set);
int set_size(intset_t *set);

void new_set(intset_t* set);

#endif /* _LINKEDLIST_H_ */
