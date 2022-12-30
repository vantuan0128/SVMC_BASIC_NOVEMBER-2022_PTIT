#include <bits/stdc++.h>
using namespace std;
int x[20],n;
vector<long> v;
void sinh(){
	for(int i=1;i<=n;i++) x[i] = i;
	while(true){
		long s = 0;
		for(int i=1;i<=n;i++){
			s = s*10 + x[i];
		}
		v.push_back(s);
		int i = n-1;
		while(i > 0 && x[i] > x[i+1]){
			i--;
		}
		if(i == 0) return;
			int k = n;
			while(x[k] < x[i]){
				k--;
			}
			swap(x[k] , x[i]);
		int l = i + 1,r = n;
			while(l < r){
				swap(x[l] , x[r]);
				l++;
				r--;
			}
	}
}
main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		sinh();
		sort(v.begin(),v.end());
		for(int i=v.size()-1;i>=0;i--){
			cout<<v[i]<<" ";
		}
		v.clear();
		cout<<endl;
	}
	return 0;
}
