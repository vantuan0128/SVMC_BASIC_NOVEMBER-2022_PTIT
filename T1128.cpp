#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	int a[n];
	for(int i = 0; i < n; i++) cin>>a[i];
	cout<<"Buoc 0: "<<a[0]<<endl;
	for(int i = 1;i < n; i++){
		int key = a[i], j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
		cout<<"Buoc "<<i<<": ";
		for(int h = 0; h <= i; h++) cout<<a[h]<<" ";
		cout<<endl;
	}
}
