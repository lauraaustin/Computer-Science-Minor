/* Laura Austin
My_stack.cpp
cpp file for My_stack */

#include"My_stack.h"
#include<vector>	// for stl vector
#include<exception>	// std::exception

// constructor


// member functions
// returns size of stack
 int My_stack::size() const{
	if (vecStack.empty())
		return 0;
	else 
		return vecStack.size();
} 
// returns top of stack
const elem& My_stack::top() const{
	if (empty())
		printf("error top(): STACK IS EMPTY\n");
	else return vecStack.front();
}
// pop alters stack so it is not const
// also not having it return anything
void My_stack::pop() {
	if (empty())
		printf("error pop(): STACK IS EMPTY\n");
	else 
		vecStack.erase(vecStack.begin()+0);
}
// puts element on top of stack
void My_stack::push(const elem& obj) {
		std::vector<int>::iterator it;
		it = vecStack.begin();
		it = vecStack.insert(it, obj);
}

bool My_stack::empty() const {
	return vecStack.empty();
	// reutrn 1 if container is size 0
	// return 0 if container is not size 0
}