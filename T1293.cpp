#include <bits/stdc++.h>

using namespace std;

int check(long n){
	while(n > 0){
		int t = n % 10;
		if(t != 2 && t != 3 && t != 5 && t != 7) return 0;
		n /= 10;
	}
	return 1;
}

int tim(int x, int a[50005], int n){
	for(int i = 0; i < n; i++){
		if(a[i] == x) return i;
	}
	return -1;
}

int main(){
	int x,a[50005],b[50005],i,n=0;
	while(cin >> x){
		if(check(x)){
			i = tim (x,a,n);
			if(i == -1){
				a[n] = x;
				b[n] = 1;
				n++;
			}
			else b[i]++;
		}
	}
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" "<<b[i]<<endl;
	}
	return 0;
}
