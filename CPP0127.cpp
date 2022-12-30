#include <bits/stdc++.h>
using namespace std;
bool SNT(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return n>1;
}
int main(){
	int t; cin>>t;
	while(t--){
		bool ok = false;
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			if(SNT(i)&&SNT(n-i)){
				cout<<i<<" "<<n-i<<endl;
				ok = true;
				break;
			}
		}
		if(ok==false) cout<<"-1"<<endl;
	}
	return 0;
}
