// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "TemplatedMy_vec.h"

int main(){
    
// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.
/* try{
	My_vec<int> V1;
	V1.insert_at_rank(0, 1);
	cout <<  V1;
}
 catch (const int * err)
 {
	cerr << err << '\n';
 } 
  */
try{
    My_vec<char> v;									// define an object v of My_vec type

	v.insert_at_rank(0,'B');   						// insert 'B' at the rank 0 into the vector v
	cout << v ; 									// use the overloaded operator << to display vector elements
	cout << "v Size : " << v.get_size() << "\n\n";	// display the vector v size

	v.insert_at_rank(0,'A');						// insert 'A' at the rank 0  to the vector v
	cout << v;										// use the overloaded operator << to display vector elements
	cout << "v Size : " << v.get_size() <<"\n\n";	// display the vector v size

  	v.insert_at_rank(10,'D');						// insert 'D' at the rank 10 into the vector v
    cout << v;										// use the overloaded operator << to display vector elements
    cout << "v Size : " << v.get_size() << "\n\n"; 	// display the vector v size
// throw error, array is CONSECUTIVE
  	v.remove_at_rank(1);							// remove a character at the rank 1 from the vector v
	cout << v;										// use the overloaded operator << to display vector elements
	cout << "v Size : " << v.get_size() << "\n\n";	// display the vector v size

 	v.replace_at_rank(0,'E');						// replace a character at the rank 0 by the character 'E'
	cout << v.elem_at_rank(0) << " ";				// use the overloaded operator << to display vector elements
	cout << "\n v Size : " << v.get_size() << "\n\n"; 	// display the vector v size
	  
	My_vec<char> v1 = v;									// create a copy v1 of the vector v using a copy constructor
	cout << v1;										// use the overloaded operator << to display the vector v1
    v1.replace_at_rank(2, 'Y');						// replace a character at the rank 2 of the vector v1 with the character 'Y'
	cout << "This is v1: \n" << v1 << "\n";			// use the overloaded operator << to display vector v1 elements

	My_vec<char> v2;										// define an object v2 of My_vec type
	v2.insert_at_rank(0,'K');						// insert 'K' at the rank 0 into the vector v2
	cout << "This is v2: \n" << v2;					// use the overloaded operator << to display vector elements
    cout << "v2 size: " << v2.get_size() << "\n\n";	// display the vector v2 size

    v2 = v1;										// test the assignment operator and copy the vector v1 to v2 
	v2.replace_at_rank(0,'5');						// Set v2 to '1','2','3','4','5'
    v2.insert_at_rank(0,'4');						// interpretting that as v2 = ['1''2''3''4''5']
	v2.insert_at_rank(0,'3');
	v2.insert_at_rank(0,'2');
	v2.insert_at_rank(0,'1'); 
	cout << v2;										// use the overloaded operator << to display vector v2
    cout << "v2 Size: " << v2.get_size() << "\n\n";	// display the vector v2 size

    int max_indexv2 = find_max_index(v2,v2.get_size());// test the function find_max_index using v2
	cout << "find max of v2 is " <<max_indexv2 << "\n"; // note that the max will be the ASCII value of the char
	sort_max(v2); 										// test the function sort_max using v2
	cout << v2;
	v2.replace_at_rank(14, 'S'); 						// replace in the vector v2 a character at the rank 14 with 'S'

}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}