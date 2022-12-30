#include <bits/stdc++.h>

using namespace std;

int n,k; 

bool cmp(int a, int b){
	return abs(a-k)<abs(b-k);
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		stable_sort(a,a+n,cmp);
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
