#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	int x[30];
	while(t--){
		int n,k; cin>>n>>k;
		for(int i = 1; i <= k; i++) x[i] = i;
		while(true){
			for(int i=1;i<=k;i++) cout<<x[i];
			cout<<" ";
			int i = k;
			while(i >= 1 && x[i] == n - k + i){
				i--;
			}
			if(i == 0){
				break;
				cout<<endl;
			}
			else{
				x[i]++;
				for(int j=i+1;j<=k;j++){
					x[j] = x[j-1] + 1;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
