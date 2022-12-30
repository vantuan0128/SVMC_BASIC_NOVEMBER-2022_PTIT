#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> dske[1001];
bool visited[1001];
int n,m,u;
void DFS(int u){
	cout<<u<<" ";
	visited[u]=true;
	for(int x : dske[u]){
		if(!visited[x]){
			visited[x]=true;
			DFS(x);
		}
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>m>>u;
		for(int i=1;i<=m;i++){
			int x,y; cin>>x>>y;
			dske[x].pb(y);
		}
		memset(visited,false,sizeof(visited));
		DFS(u);
		for(int i=1;i<=1001;i++) dske[i].clear();
		cout<<endl;
	}
	return 0;
}
