/*
 *  linkedlist.h
 *  
 *
 *  Created by Vincent Gramoli on 1/12/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _INTSET_H_
#define _INTSET_H_

#include "harris.h"

int set_contains(intset_t *set, val_t val, int transactional);
int set_add(intset_t *set, val_t val, int transactional);
int set_remove(intset_t *set, val_t val, int transactional);

#endif /* _INTSET_H_ */