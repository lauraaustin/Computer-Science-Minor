#include "std_lib_facilities_4.h"

long long int f(long long int n, long long int k){
	long long int b;
	b = k+2;
	if (n == 0) b = 8;
	else b = b+4*n + f(n-1,k+1);
	long long int ans;
	ans = b+k;
	cout << "this is answer: " << ans << endl;
	return ans;
}
int main(){
	int long long h;
	h = f(2,4);
	
}