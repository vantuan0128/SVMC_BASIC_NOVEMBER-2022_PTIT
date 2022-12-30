#include <bits/stdc++.h>
using namespace std;
long USCLN(long a, long b){
	if(b==0) return a;
	return USCLN(b,a%b);
}
long long BSCNN(long a, long b){
	return a * b / USCLN(a,b);
}
int main(){
	int t ; cin>>t;
	while(t--){
		long a,b; cin>>a>>b;
		cout<<BSCNN(a,b)<<" "<<USCLN(a,b)<<endl;
	}
	return 0;
} 
