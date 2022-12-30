#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> dske[1001];
bool visited[1001];
int n,m,u;

void BFS(int u){
	queue <int> q;
	visited[u]=true;
	q.push(u);
	while(!q.empty()){
		int v = q.front(); q.pop();
		cout<<v<<" ";
		for(int x : dske[v]){
			if(!visited[x]){
				q.push(x);
				visited[x]=true;
			}
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
		BFS(u);
		for(int i=1;i<=1001;i++) dske[i].clear();
		cout<<endl;
	}
	return 0;
}
