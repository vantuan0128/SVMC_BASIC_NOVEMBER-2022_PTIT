#include <iostream>
#include <math.h>
using namespace std;
long tongChuso(long n){
	int sum1=0;
	int N;
	while(n>0){
	    N=n%10;
	    sum1=sum1+N;
	    n/=10;
	}
	return sum1;
}

long tongThuaso(long n){
	int sum2=0;
	for(int i=2;i<=n;i++){
	    while(n%i==0){
	        sum2=sum2+tongChuso(i);
	        n/=i;
	    }
	}
	return sum2;
}

int main(){
    long t;
    cin>>t;
	while(t--){
		long n;
		cin>>n;
		if((tongChuso(n)==tongThuaso(n))) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
return 0;
}
