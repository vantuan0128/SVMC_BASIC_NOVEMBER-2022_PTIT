#include <bits/stdc++.h>
using namespace std;
int n,x[20];
bool check(){
	for(int i = 1;i<=n-1;i++){
		if(abs(x[i]-x[i+1])==1) return false;
	}
	return true;
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			x[i] = i;
		}
		int ok =false;
		while(!ok){
			if(check()){
				for(int i=1;i<=n;i++){
					cout<<x[i];
				}
				cout<<endl;
			}
			int i=n-1;
			while(i>=1&&x[i]>x[i+1]){
				i--;
			}
			if(i==0) ok=true;
			else{
				int k=n;
				while(x[k]<x[i]) k--;
				swap(x[k],x[i]);
				int l=i+1,r=n;
				while(l<r){
					swap(x[l],x[r]);
					l++;r--;
				}
			}	
		}
	}
	return 0;
}
