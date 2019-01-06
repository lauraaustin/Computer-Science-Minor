/* Application.cpp
contains the main
Laura Austin
*/
#include <vector>
#include <iostream>
#include "My_stack.h"
#include <stdexcept>
using namespace std;
void spans1(vector<int> &x);								// spans1 function
void print(const vector<int> v);							// function for printing vectors
void spans2(vector<int> &, My_stack stack);					// spans2 function

////////////////////////////////////////////////
int main(){
	
try{
	int n_stack; // stack size
	/////////stack//////////////////
	My_stack stack1;
	cout << "My_stack output test: \n";
	cout << "Stack size is " <<stack1.size() <<endl;		// checking stack size before
	cout << "Objects inserted in order: ";
	if (stack1.empty()){									// inputing {0,1,2,3,4,5} into stack
		for (int i = 0; i<=5; i++){
			stack1.push(i);
			cout << stack1.top() << ' ';					// printing the stack
		}
		n_stack = stack1.size();							// checking stack size after
		cout << "\nStack size is " << stack1.size() << '\n';
	}
	cout << "Objects are removed as: ";
	while(!stack1.empty()){									// outputing the stack
		cout << stack1.top() <<' ';							// to show "last in-first out"
		stack1.pop();
	}
	cout << endl;
}
catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}

try{	
	//////////////////end stack stuff//////////////
	/////////////////////spans1
	cout << "\nSpans1 output:\n";				// the following v's represent test vectors.
 	vector<int> v ;
	v = {6, 3, 4, 5, 2};						// test vector 1 for spans1 algorithm
	printf("\nThe input vector x: \t");
	print(v);									// printing the test vector.
	printf("\nThe span of x, s: \t");			// implementing spans1 algorithm.
	spans1(v);									// note that spans1 contains print function.
	v = {1, 2, 3, 5, 6};						// test vector 2 for spans1 algorithm
	printf("\nThe input vector x: \t");
	print(v);
	printf("\nThe span of x, s: \t");
	spans1(v);
	v = {1, 2, 3, 2, 1};						// test vector 3 for spans1 algorithm
	printf("\nThe input vector x: \t");
	print(v);
	printf("\nThe span of x, s: \t");
	spans1(v);
	////////////////end of spans1/////////////////
	//////////////////spans2
	cout << "\n\nSpans2 output:\n";
	My_stack stack;
	v = {6, 3, 4, 5, 2};						// test vector 1 for spans2 algorithm
	printf("\nThe input vector x: \t");
	print(v);
	printf("\nThe span2 of x, s: \t");
	spans2(v,stack);
	v = {1, 2, 3, 5, 6};						// test vector 2 for spans2 algorithm
	printf("\nThe input vector x: \t");
	print(v);
	printf("\nThe span2 of x, s: \t");
	spans2(v,stack);
	v = {1, 2, 3, 2, 1};						// test vector 3 for spans2 algorithm
	printf("\nThe input vector x: \t");
	print(v);
	printf("\nThe span2 of x, s: \t");
	spans2(v,stack);
}
catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
};

void spans1(vector<int> &x){						// Defined a reference vector in order to be
	int n = x.size();								// able to use a reference vector in main.
	vector<int> s;									// s is my spans1 vector 
	for (int i = 0; i <= (n - 1); i++){				// implementation of algorithm on assignment
		int  j = 1;
			while ( (j <= i) && ((x[i-j]) <= x[i]) ) 
				j++;
		s.insert(s.begin()+i,j);					// same as s[i]=j
	}
	print(s);
}
 void spans2(vector<int> &x, My_stack stack){
	int i;		// i is index of x. 
	int j;	// j is only accessible index of stack, top.
	vector<int> span;
		for (i = 0; i < x.size(); i++){
			if (!stack.empty())						// if stack is nonempty, define j.
				j = stack.top();
			while(!stack.empty() && (x[i] >= x[j])){// condition for popping the stack
				stack.pop();
				if (stack.empty())					// this check is because stack may empty out 
					break;							// prevents error from calling top() to empty stack
				else j = stack.top();
			}
			if (stack.empty())						// if stack is empty, put i+1 to span vector at index i.
				span.insert(span.begin()+i,(i+1));				
			else									// if stack is nonempty, i-j to span vector at index i.
				span.insert(span.begin()+i,(i-j));
			stack.push(i);							// always push i.
		}	
	print(span);
}
void print(const vector<int> v){					// print function, just iterates through any vector
	for (int i = 0; i < v.size(); i++)				// const vector so that it does not change vector
		cout << v[i] << ' ';
}
