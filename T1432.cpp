#include <bits/stdc++.h>
using namespace std;
int x[20000],n,a[20000];
int main(){
	int t; cin >> t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++) cin >> a[i];
		int i = n - 2;
		while(i >= 0 && a[i] > a[i+1]){
			i--;
		}
		if(i < 0){
			for(int i = 0; i < n; i++) cout << i + 1 << " ";
			cout << endl;
		}
		else{
			int k = n - 1;
			while(a[k] < a[i]){
				k--;
			}
			swap(a[k],a[i]);
			int l = i + 1, r = n - 1;
			while(l < r){
				swap(a[l],a[r]);
				l++;r--;
			}
			for(int i = 0; i < n; i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
