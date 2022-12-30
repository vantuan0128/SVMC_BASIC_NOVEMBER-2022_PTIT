#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long process(long a, long b){
	if(b==0) return 1;
	if(b==1) return a;
	long long mu = process(a,b/2);
	if(b%2==0) return ((mu%MOD)*(mu%MOD))%MOD;
	else return a*((mu*mu%MOD))%MOD;
}
int main(){
	long a=1, b=1;
	do{
		cin >> a >> b;
		if(a==0&&b==0) break;
		cout<<process(a,b)<<endl;
	}while(1);
	return 0;
}
