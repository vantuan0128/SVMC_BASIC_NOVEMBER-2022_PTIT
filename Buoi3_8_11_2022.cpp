/*

Liet ke cac SNT < n
Sang Eratosthenes
del 1
tiep theo chua del i ng to
xoa cac boi cua i ke tu i*i
 
*/ 
#include <bits/stdc++.h>
using namespace std;
const int MN = 1000000; //2M
bitset<MN> s; //sang
const int Pow[] = {10,100,1000,10000,100000, 1000000};
const int BADDIG[]={0,0,0,0,1,0,1,0,1,0}; //04568
// cac so ng to < n
int Sieve(int n){
	for(int i = 2; i < n; i++) s[i] = 1; // gan moi bit la 1
	s[0]=s[1]=0; //dej 0, 1
	//del cac boi cua 2 ke tu 4
	for(int j=4; j<n; j+=2) s[j]=0;
	int sn = (int) sqrt(n);
	for(int i = 3; i <= sn; i+=2){
		if(s[i]){
			for(int j = i*i; j < n; j+=i){
				s[j] = 0;
			}
		}
	}
	return s.count();
}

//Sinh cac SNT ghi file
int Sieve(int n, const char * fn){
	int m = Sieve(n);
	ofstream f(fn);
	f << 2 << endl;
	for(int i=3; i<n; i+=2){
		if(s[i]) f << i << endl;
	}
	f.close();	
}

void Run(){
	int n = 700;
	int m = Sieve(n);
	if(s[2]) cout<<2;
	for(int i = 3; i < n; i+=2){
		if(s[i]) cout << i << " ";
	}
	cout<<"\n Total "<<m;
}

/*---------------
	Liet ke 11 SNT cat duoc < 1M
	75787 || Euler Project
	Sieve(1M)
	AllCut #x - 1 nhat tao ra 2 so a|b deu trong sang
	Mat ma voi khoa cong khai
	Alain Turing Tunscatable
	Loai 0468
---------------*/

bool OldAllCut(int x){
	// 12345 a = x % 100; b = x / 100
	int m = 10,a,b;
	while(m < x){
		a = x % m;
		if(s[a]==0) return false;
		b = x / m;
		if(s[b]==0) return false;	
		m *= 10;	
	}	
	return true;
}

bool AllCut(int x){
	// 12345 a = x % 100; b = x / 100
	for(int i=0;Pow[i]<x;i++){
		if(s[x % Pow[i]]==0) return false;
		if(s[x / Pow[i]]==0) return false;
	}	
	return true;
}

bool Good(int x){
	while(x){
		if (BADDIG[x % 10]) return false;
		x /= 10;
	}	
	return true;
}

void Cut(int n){
	Sieve(n);
	//for(int i=3;i<60;i+=2) if(s[i]) cout<<" "<<i;
	//for(int i=n-50;i<n;++i) if(s[i]) cout<<" "<<i;
	cout<<endl;
	int count = 0;
	for(int p = 23; p < n; p += 2){
		if(s[p]){ // p nguyen to
			if(Good(p)){
				if(AllCut(p)){
					cout<<" "<<p;
					count++;
				}
			}
		}
	}
	cout<<"\nTotal: "<<count;
} 

main(){
	Cut(MN);
	//cout<<Good(12397);
	//Run();
	//Sieve(1000000,"PIMER1M.DAT");
	return 0;
}
