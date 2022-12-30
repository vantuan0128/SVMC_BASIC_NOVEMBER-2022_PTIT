#include <bits/stdc++.h>
using namespace std;
long process(long n){
	long tong = 0;
	while(n>0){
		tong += n%10;
		n /= 10;
	}
	return tong;
}
int main(){
	int t ; cin>>t;
	while(t--){
		long n; cin>>n;
		cout<<process(n)<<endl;
	}
	return 0;
}
