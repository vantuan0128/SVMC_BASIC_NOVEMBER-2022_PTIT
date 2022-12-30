#include <bits/stdc++.h>
using namespace std;
bool SNT(long long n){
	for(int i=2;i<=sqrt(n);i++){
		if(n % i == 0) return false;
	}
	return n > 1;
}
long long process(long long n){
	long long res;
	for(int i=2;i<=sqrt(n);i++){
		while(n % i == 0){
			res = i;
			n /= i;
		}
	} 
	if(n != 1) res=n;
	return res;
}
int main(){
	int t; cin>>t;
	while(t--){
		long long n; cin>>n;
		cout<<process(n)<<endl;
	} 
	return 0;
}
