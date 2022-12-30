#include <bits/stdc++.h>
using namespace std;
using ll= long long;
void process(string s, string t){
	for(int i=0;i<s.length();i++){
		if(s[i]=='6') s[i]='5';
	}
	for(int i=0;i<t.length();i++){
		if(t[i]=='6') t[i]='5';
	}
	ll min = stoll(s)+stoll(t);
	cout<<min<<" ";
	for(int i=0;i<s.length();i++){
		if(s[i]=='5') s[i]='6';
	}
	for(int i=0;i<t.length();i++){
		if(t[i]=='5') t[i]='6';
	}
	ll max = stoll(s)+stoll(t);
	cout<<max<<endl;
}
int main(){
	string s; cin>>s;
	string t; cin>>t;
	process(s,t);
	return 0;
}
