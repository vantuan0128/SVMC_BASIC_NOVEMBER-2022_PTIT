#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	map<int,int> mp;
	while(t--){
		int n; cin>>n;	
		for(int i=1;i<=n;i++){
			int x ; cin>>x;
			mp[x]++;
		}
		for(auto it : mp){
			if(it.second % 2 == 1){
				cout<<it.first<<endl;
				break;
			}
		}
		mp.clear();
	}
	return 0;
}
