/* My_stack.h
Laura Austin
header file for stack data type
*/
	
#include <ostream>
#include<vector>
using namespace std;
typedef int elem;
class My_stack {
private:
	// member variables
	vector<elem> vecStack;	// vector of elements 

public:
	// member functions

	
	int size() const;
	const elem& top() const; // returns top obj
	void pop(); // removes top obj
	void push(const elem& obj); // puts obj on stack
	bool empty() const; // checks stack for emptiness
};
