#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	int x[1005];
	while(t--){
		int n,k; cin>>n>>k;
		for(int i = 1; i <= k; i++) cin>>x[i];
		int i = k;
		// 1 2 4 5 --> // 1 2 3 5 
		while ( i >= 1 && x[i] == x[i-1] + 1){
			i--;	
		}
		if(i == 1){
			//To hop dau tien -> In ra to hop cuoi cung
			for(int j = 1;j <= k; j++){
				cout<<n - k + j<<" ";
			}
			cout<<endl;
		}
		else{
			x[i]--;
			for(int j = i + 1; j <= k; j++){
				x[j] = n - k + j;
			}
			for(int i = 1;i <= k; i++){
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}	
	}
	return 0;
}
