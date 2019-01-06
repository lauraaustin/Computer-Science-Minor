/* 
    File: my_allocator.c

    Author: Laura Austin
            Department of Computer Science
            Texas A&M University
    Date  : 09/18/2017

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include<stdlib.h>
#include "my_allocator.h"
#include "free_list.h"
#include<stdio.h>



/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE MY_ALLOCATOR */
/*--------------------------------------------------------------------------*/

/* Don't forget to implement "init_allocator" and "release_allocator"! */

FL_HEADER * start;
FL_HEADER * list;
unsigned int remaining;

// reserves memory in of size basic block size of FL

unsigned int init_allocator(unsigned int _basic_block_size, unsigned int _length){
	// Should just be able to call FL_add which invokes malloc(x) which you compare here
	
	list = (FL_HEADER*)malloc(_length + sizeof(FL_HEADER*));
	start = (FL_HEADER*)malloc(_length + sizeof(FL_HEADER*)); 
	
	start->prev = NULL;

	FL_add(list, start);
	remaining = _length;			// allocating specified amount _length
	return _length;
}
// cuts off portion 
FL_HEADER * newstart;
Addr my_malloc(size_t _length) {
	int Lnew = _length + sizeof(FL_HEADER);
	FL_HEADER * temp = start->next;	// temp starts at top of list
	while (temp != NULL){				// while temp is non-null
		if (temp->length >= _length)	// if temp length >= input length
			temp = temp->next;			// traverse
		else {			// otherwise 
			int xnew = temp->length;	
			FL_remove(temp);			// take away the temporary pointer
			remaining = xnew - Lnew;	// subtract old and new
			newstart = temp->header;		// newstart is assigned a new header
		}
	}
	
	
  if (remaining <= 0)			// If there is not enough left 
	  return NULL;					// memory, then NULL is returned
  else{								// If there is enough memory left then:
	  size_t newlength;
	  int oldlength = sizeof(start);
	  newlength = oldlength + _length;	// computing the new remaining memory
	  //(char)newstart = newlength;
	  FL_add( list, newstart);
	  //return start;				// return to the new address 
	  }
  return (Addr)newstart;
}

int my_free(Addr _a) {
  /* Same here! */
  free(_a);
  FL_HEADER * adressfreed = (FL_HEADER*)((char*)_a - sizeof(FL_HEADER)); // catches the address
  printf("free node %x\n", adressfreed);					// prints the freed
  printf("free node length is %d\n", adressfreed->length);
  return 0;
}

int release_allocator(){
	FL_HEADER *pointer = list->header;		// pointer to the header
	while (pointer != NULL){
		free(pointer);					// frees pointer
		pointer = pointer->next;		// iterates
	}
}

