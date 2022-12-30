#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	int x[20];
	while(t--){
		string s; cin>>s;
		int n = s.length();
		for(int i=1;i<=n;i++) x[i]=i;
		int ok=false;
		while(!ok){
			for(int i=1;i<=n;i++){
				cout<<s[x[i]-1];
			}
			cout<<" ";
			int i = n-1;
			while(i >= 1 && x[i] > x[i+1]){
				i--;
			}
			if(i==0){
				cout<<endl;
				ok=true;
			}
			else{
				int k = n;
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
