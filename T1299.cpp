#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		long so1 = 0, so2 = 0;
		for(int i=0;i<n;i++){
			if(i%2==0) so1 = so1*10 + a[i];
			else so2 = so2*10 + a[i];
		}
		cout<< so1 + so2 << endl;
	}
	return 0;
}
