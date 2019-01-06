/* 
    File: free_list.c

    Author: Laura Austin
            Department of Computer Science
            Texas A&M University
    Date  : Sept 15, 2017

    Modified: 

    This file contains the implementation of the module "FREE_LIST".

*/
#include "free_list.h"
#include<stdlib.h>
#include<stdio.h>


void FL_remove(FL_HEADER *block){
/* Remove the given block from given free list. The free-list
pointer points to the first block in the free list. Depending
on your implementation you may not need the free-list pointer.*/
	if (block->next->prev){
		FL_HEADER * W = block->next;			// next node
		FL_HEADER * U = block->prev;			// previous node
		U->next = W;						// attach previous to next
		W->prev = U;						// attach next to previous
		int sizeremoved = block->length;		// return length of block removed
		free(block);
		printf("successfully removed %d of memory.\n\n", sizeremoved);
	}
	else printf("Could not find block\n");
}


void FL_add(FL_HEADER * list, FL_HEADER *block){
/* Add a block to the free list */
/* Adding it to the beginning of the free list*/
	FL_HEADER * header = list->header;  	// calling a header a header of list
	if (header == NULL){ // LIST IS EMPTY
		header = block;		// then header = block
		return;
	}
	FL_HEADER * point = header;	// pointer to the header called point
	header = block;				// header = block
	point->prev = block;		// assigning pointers to new spots
	block->next = point;		// assigning next pointer to header;
}

