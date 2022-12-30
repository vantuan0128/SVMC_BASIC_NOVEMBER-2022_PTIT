#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	int a[256]={0};
	for(char x : s){
		a[x]=1;
	}
	int dem=0;
	for(int i=0;i<256;i++){
		if(a[i]==1) dem++;
	}
	cout<<dem<<endl;
	return 0;
} 
