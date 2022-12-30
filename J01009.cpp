#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long xuli(int n){
	if(n == 0 || n == 1) return 1;
	return n * xuli(n-1);
}
int main(){
	int n; cin>>n;
	long long sum = 0;
	for(int i=1;i<=n;i++){
		sum += xuli(i);
	}
	cout<<sum<<endl;
	return 0;
}
