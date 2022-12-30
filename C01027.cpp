#include <bits/stdc++.h>
using namespace std;
long USCLN(int a, int b){
	if(b==0) return a;
	return USCLN(b,a%b);
}
int main(){
	int t; cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<USCLN(a,b)<<endl;
	}
	return 0;
}
