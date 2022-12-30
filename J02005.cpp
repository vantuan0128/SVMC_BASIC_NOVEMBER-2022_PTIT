#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	set<int> se1;
	set<int> giao;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		se1.insert(x);
	}
	for(int i=1;i<=m;i++){
		int x; cin>>x;
		if(se1.find(x) != se1.end()){
			giao.insert(x);
		}
	}
	for(int x : giao) cout<<x<<" ";
	return 0;
}
