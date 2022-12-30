#include <bits/stdc++.h>
using namespace std;
int check(int a[],int n,int k){
	for(int i=0;i<n;i++){
		if(a[i]==k) return i+1;
	}
	return 0;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(check(a,n,k) != 0) cout<<check(a,n,k)<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
