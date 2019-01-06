#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;
// https://en.wikipedia.org/wiki/Binary_search_algorithm
// https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception
//
	int comparisonnum = 0;
int BinarySearch(const vector<int> &L , int target, int low, int high);
int main(){
	//vector<int> v = {1,3,7,15,31,63,127,255,511,1023,2047};
	vector<int> v ={2047,1023,511,255,127,63,31,15,7,3,1};
	cout << "vector tested is: < ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] <<' ';
	cout << '>'<< '\n';
	int target ;
	int size = v.size();
	target = 1;
	int low = 0 ; // int LOW  
	int high = size-1; ; // int HIGH */
	// Ranges

	BinarySearch(v,target, low, high);
	
return 0;	
}
int BinarySearch(const vector<int> &v , int k, int low, int high){
	// check for sort and throw error
	bool asc;
	bool desc;
	for (int i=0; i < (v.size()-1); i++){
		asc = (v.at(i) <= v.at(i+1));
		if (asc == 0) break;
	}
	for (int i=0; i < (v.size()-1); i++){
		desc = (v.at(i) >= v.at(i+1));
		if (desc == 0) break;
	}
	//
	if ((desc == 0)&&(asc == 0)&& (v.size() != 1)){
			throw std::invalid_argument("Input vector not sorted");
	}

	int mid;

	if ((asc == 1) || (v.size() == 1)){
		if (comparisonnum++, low > high ) 
			return -1;
		else{
			mid = floor(( low + high )/2);
		
			if (comparisonnum++ , k == v[mid]){
				cout << " found element " << v[mid] << " after " << comparisonnum<< " comparisons.\n";
				return mid;
			}
			else if (comparisonnum++, k < v[mid]) {
				BinarySearch(v, k , low, mid - 1);
			}
			else {
				BinarySearch(v, k , mid + 1, high);
			}
		}
		return -1; // not found
	}
	//////////////////////////////////////////////////////////////////////
	else if (desc == 1){
		if (comparisonnum++, low > high)
			return -1;
		else{
			mid = ( low + high )/2;
			if (comparisonnum++, k == v[mid]) {
				cout << " found element " << v[mid] << " after " << comparisonnum<< " comparisons.\n";
				return mid;
			}
			else if (comparisonnum++,k > v.at(mid)) {
				BinarySearch(v, k , low, mid - 1);
			}	
			else {
				BinarySearch(v, k, mid + 1, high);
			}
		}
		return -1; // not found
		
}
}