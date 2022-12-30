#include <bits/stdc++.h>
using namespace std;
void init(){
	string s;
	getline(cin,s);
	if(s[0] -'0' + s[4] - '0' == s[8] -'0') cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	int t; cin>>t;
	cin.ignore();	
	while(t--){
		init();
	}
	return 0;
}
