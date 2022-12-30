#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		long a[n];
		long tong = 0;
		for(int i=0;i<n-1;i++){
			cin>>a[i];
			tong += a[i];
		}
		long sum = n * (n+1) / 2;
		cout<<sum - tong<<endl;
	}
	return 0;
}
