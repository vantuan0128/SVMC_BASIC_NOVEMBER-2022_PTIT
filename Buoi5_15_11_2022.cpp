/*----------
15/11/2022 Hoan vi (Permutation)
n = 4, 4!= 24 1234 1243 1324 1342 1423 1432
			  2134 2143 2314 2341 2413 2431

H1. Liet ke moi HV cua n phan tu
H2. Given n, k tim HV thu k. n = 4, k = 12
	2431
H3. Given h tim k?
-----------*/
#include <bits/stdc++.h>
using namespace std;
const int MN = 16;
int h[MN],n;
//Tim HV sat sau
//True neu co HV sat sau
//Next 14'532 15234
//Duyet nguoc tim diem gay i: h[i] < h[i+1]
//Neu ko co i: return false
//Duyet nguoc tim diem vuot: h[i] < h[j]
//Doi cho i, j
//Lat h[i+1...]
//h[1...n]  
bool Next(){
	int i,j;
	//Tim diem gay
	for(i = n-1; i > 0; --i){
		if(h[i] < h[i+1]) break;
	}
	if(i == 0) return false;
	//Tim diem vuot
	for(j = n; j > i; --j){
		if(h[j] > h[i]) break;
	}
	int t = h[i]; h[i] = h[j]; h[j] = t;
	//Lat h[i+1...n]
	++i; j = n;
	while(i < j){
		t = h[i]; h[i] = h[j]; h[j] = t;
		++i;--j;
	}
	return true;
}
void Print(int a[], int d, int c, const char* msg = ""){
	cout << msg;
	for(int i = d; i <= c; ++i){
		cout << " " << a[i];
	}
}


void Go(){
	cout<<" ? ";
	fflush(stdin);
	if(cin.get()=='.'){
		exit(0);
	}
}

void Run(){
	int n = 4;
	for(int i = 0; i <= n; ++i) h[i] = i;
	do{
		Print(h,1,n,"\n"); Go();
	}while(Next());
}

main(){
	Run();
	cout<<"\n The End";
	return 0;
}
