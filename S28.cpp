#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,a[20],used1[20],used2[20]; 
char b[20];
vector<string> q;
vector<string> p;
void add1(){
	string s;
	for(int i=1;i<=n;i++){
		s = s + to_string(a[i]);
	}
	q.push_back(s);
}
void add2(){
	string t;
	for(int i=1;i<=n;i++){
		t = t + b[i];
	}
	p.push_back(t);
}
void ql1(int i){
	for(int j=1;j<=n;j++){
			a[i]=j;
			if(i==n) add1();
			else ql1(i+1);
	}
}
void ql2(int i){
	for(int j=1;j<=n;j++){
		if(!used2[j]){
			used2[j]=1;
			b[i]=char(j+'A'-1);
			if(i==n) add2();
			else ql2(i+1);
			used2[j]=0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ql1(1);
	ql2(1);
	for(string x : p){
		for(string y : q){
			cout<<x<<y<<endl;
		}
	}
	return 0;
}
