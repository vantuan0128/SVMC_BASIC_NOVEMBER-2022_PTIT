#include <bits/stdc++.h>
using namespace std;
bool SNT(long n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return n>1;
}
bool check1(long n){
	while(n>0){
		if(!SNT(n%10)) return false;
		else n /= 10;
	}
	return true;
}
bool check2(long n){
	int sum =0 ;
	while(n>0){
		sum += n%10;
		n /= 10;
	}
	if(SNT(sum)) return true;
	else return false;
}
void process(long a, long b){
	int dem = 0;
	for(int i=a;i<=b;i++){
		if(check2(i)&&check1(i)&&SNT(i)) dem++;
	}
	cout<<dem<<endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		long a,b; cin>>a>>b;
		process(a,b);
	}
	return 0;
}
