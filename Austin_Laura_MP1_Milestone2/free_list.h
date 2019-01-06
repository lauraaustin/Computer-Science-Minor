/* 
    File: free_list.h

    Author: Laura Austin
            Department of Computer Science
            Texas A&M University
    Date  : September 15, 2017

    Modified: 

    This file contains the implementation of the module "free_list".

*/
#include<stdlib.h>



// list blocks type
typedef struct fl_header {
	int length = sizeof(struct fl_header*);
	struct fl_header *prev, *next, *header;
	fl_header( int _length = 0, struct fl_header *p = NULL, struct fl_header *n = NULL, struct fl_header *head = NULL)
		: length(_length), prev(p), next(n), header(head){}
} FL_HEADER;


void FL_remove(FL_HEADER *block);
/* Remove the given block from given free list. The free-list
pointer points to the first block in the free list. Depending
on your implementation you may not need the free-list pointer.*/
void FL_add( FL_HEADER *list, FL_HEADER *block);
/* Add a block to the free list */

 