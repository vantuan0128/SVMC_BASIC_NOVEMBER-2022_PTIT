#include <bits/stdc++.h>
using namespace std;

//Ham phan hoach Lomuto: Tra ve chi so cua khoa (pivot)
int Partition(int a[],int l ,int r){
	int i = l - 1, pivot = a[r];
	for(int j = l; j < r; j++){
		//neu a[j] > pivot: bo qua
		if(a[j] <= pivot){
			++i;
			swap(a[i],a[j]);
		}
	}
	++i;
	swap(a[i],pivot);
	return i;
}

void QuickSort(int a[], int l, int r){
	if(l < r){
		int pos = Partition(a,l,r);
		//xet de quy ve day ben trai
		QuickSort(a,l,pos-1);
		QuickSort(a,pos+1,r);
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		for(int i = 0;i < n;i++) cin>>a[i];
		QuickSort(a,0,n-1);
		for(int i=0;i < n;i++) cout<<a[i]<<" ";
		cout<<endl;	
	}
	return 0;
}
