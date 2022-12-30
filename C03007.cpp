#include <bits/stdc++.h>
using namespace std;
bool SNT(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return n>1;
}
bool STN(int n){
	int socu=n;
	int somoi=0;
	while(n>0){
		somoi = somoi*10 + n%10;
		n /= 10;
	}
	if(somoi==socu) return true;
	else return false;
}
void process(int a, int b){
	int dem=0;
	for(int i=a;i<=b;i++){
		if(SNT(i)&&STN(i)){
			cout<<i<<" ";
			dem++;
			if(dem==10){
				cout<<endl;
				dem=0;
			}
		}
	}
	cout<<endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		process(a,b);
		cout<<endl;
	}
	return 0;
}
