#include <bits/stdc++.h>
using namespace std;
int x[30],n;
int a[30];
// Sinh hoan vi
void sinh(){
	for(int i=1;i<=n;i++){
		x[i]=i;	
	}
	while(true){
		for(int i=1;i<=n;i++){
			cout<<a[x[i]-1]<<" ";
		}
		cout<<endl;
		int i = n-1;
		while(i > 0 && x[i] > x[i+1]){
			i--;
		}
		if(i==0) return;
		int k=n;
		while(x[k]<x[i]){
			k--;
		}
		swap(x[k],x[i]);
		int l=i+1; int r=n;
		while(l<r){
			swap(x[l],x[r]);
			l++;r--;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sinh();
	return 0;
}
