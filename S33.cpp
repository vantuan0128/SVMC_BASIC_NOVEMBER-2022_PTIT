#include <bits/stdc++.h>
using namespace std;
char c;
int n;
int x[20];
bool check(){
	for(int i=1;i<=n-1;i++){
		if(x[i]>x[i+1]) return false;
	}
	return true;
}
int main(){
	cin>>c; //n
	cin>>n; //k
	//AA
	for(int i = 1; i <= n; i++) x[i] = 1;
	int ok = false;
	while(!ok){
		//In AA - 11
		if(check()){
			for(int i = 1; i <= n; i++){
				cout<<char(x[i] + 'A' - 1);
			}
			cout<<endl;
		}
		int i = n;
		//i>=1 && x[i] != 4
		while(i >= 1 && x[i] == c - 'A' + 1){
			i--;
		}
		if(i == 0){
			ok = true;
		}
		else{
			x[i]++;
			for(int j = i + 1; j <= n; j++){
				x[j] =  1;
			}
		}
	}
	return 0;
}
