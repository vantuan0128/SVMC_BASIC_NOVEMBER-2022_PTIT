#include <bits/stdc++.h>
using namespace std;
bool check(long n){
	if(n<2) return false;
	if(n==2) return true;
	if(n%2==0 && n!=2) return false;
	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return false;
	}
	return n>1;
}
int main(){
	int t; cin>>t;
	while(t--){
		long n; cin>>n;
		if(check(n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
