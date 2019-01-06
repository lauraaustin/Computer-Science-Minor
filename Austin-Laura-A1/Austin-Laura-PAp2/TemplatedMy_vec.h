/*My_vec.h
Laura Austin
Header file for a vector data structure.
*/

#include <ostream>

using namespace std;

template <typename T> class My_vec {
	
	//member variables, 
	// num of elements and current vec size
	int size, capacity;
	T *ptr;

public:	
	//member functions
	const int def_cap = 10; 
	My_vec()
	{
		size = 0;
		capacity = def_cap;
		ptr = new T[capacity];
	}
	~My_vec()
	{
		delete[] ptr;
	}
	My_vec(const My_vec& vec)
	{
		for (int i = 0; i < size ; i ++)
			ptr[i] =vec.ptr[i];
	}
	My_vec& operator=(const My_vec& vec)
	{
		if(this != &vec){								// copy assignment operator
			delete ptr;						 					// delete old 
			size = vec.size;										// size is a member of object vec , 
			capacity = vec.capacity;								// passing vec.size into size
			ptr = new T[vec.capacity];							// size is a member of object vec
			for (int i=0; i < vec.size; i++)
				ptr[i] = vec.ptr[i];
		}
	return *this;
	}
	int get_size() const
	{
		return size;
	}
	int get_capacity() const
	{
		return capacity;
	}
	T &operator[](int i) const
	{
		if (i<0 || i > ( size - 1 ))
			throw"RANK OUT OF RANGE";
		else
			return ptr[i];					// ptr[i] returned if [] is given
	}
	T &operator[](int i)
	{
		return ptr[i];	
	}
	bool is_empty() const
	{
		return size == 0; 		
	}
	T& elem_at_rank(int r) const
	{
		if (r < 0 || r > (size-1)) 				// can get elements from [0,size-1]
			throw"RANK OUT OF RANGE";
		else
			return ptr[r];		
	}
	void insert_at_rank(int r, const T& elem)
	{
		if (r<0 || r >= capacity)
			throw"RANK OUT OF RANGE";
		else if (r < (capacity-1) && r > (size+1))
			throw"RANK OUT OF RANGE";	
		
		else if (size >= capacity){
			T * vec2 = new T[capacity*2];	// More memeory allocated
			for (int i = 0; i < size; i++)		// copying contents
				vec2[i] = ptr[i];

			delete [] ptr; 	// delete old vec
			ptr = vec2;							// make vec2 new vector
			for (int j = size - 1;  j>=r; j--) // add the element as normal
				ptr[j+1] = ptr[j]; 				// now that memory is allocated
			size++;
			ptr[r] = elem; 					
		} 						
		else {
			for (int j = size - 1;  j>=r; j--)	// insert element and shifting
				ptr[j+1] = ptr[j]; 
			size++;
			ptr[r] = elem; 						// copy contents of the vector
		}		
	}
	void replace_at_rank(int r, const T& elem)
	{
		if (r < 0 || r > (size-1))
			throw"RANK OUT OF RANGE";
		else 
			ptr[r] = elem;		
		}
		void remove_at_rank(int r)
		{
		if (r >= 0 && r <size){
			for (int j = r+1; j < size; j++)
				ptr[j]=ptr[j+1]; 				// shift elements
			size--;
		}
		else throw"RANK OUT OF RANGE";
	}
};
	
	template <typename T> ostream& operator<<(ostream& out, const My_vec<T>& vec)
	{
		for (int i = 0; i < vec.get_size(); i++)
			out << '[' << vec.elem_at_rank(i) << ']' << endl;
		return out;		
	}
	template <typename T> int find_max_index(const My_vec<T>& v,int size)
	{
		int j = 0;
		int i = 1;
		int vecsize = v.get_size();
		if (size > vecsize) throw"RANK OUT OF RANGE";
		if (size == 1)return 0;
		else {
			while(i < size){
				if(v[j] < v[i])
					j = i;
			i++;
			}
		return j; // the current max index
		}		
	}
	template <typename T> void sort_max(My_vec<T>& vec)
	{
		if (vec.is_empty())
			throw"CANNOT SORT EMPTY VECTOR";
	/*  	My_vec vec2 = vec; // holding vector
		int size = vec.get_size();
		for (int i = 0; i < (size-1); i++){
			int index = find_max_index(vec,size);
			vec[index] = vec2[i];
			vec.remove_at_rank(index);
		} */
		My_vec<T> vec2 = vec;
		int size = vec.get_size();
		int index;
		int i = 0;
		while(size>i){
			index = find_max_index(vec,vec.get_size());
			vec2.insert_at_rank(0, vec[index]);
			vec.remove_at_rank(i);
			--size;
		} 
		vec = vec2; 		
	}