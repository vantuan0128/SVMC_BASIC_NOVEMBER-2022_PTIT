/* 
		Bai 2. So hoc (Arithmetic)
	Gcd, Lcm, Day uoc chung lon nhat, cong phan so
Uoc chung lon nhat cua 2 so tu nhien: UCLN 
Greatest Common Divisor

*/
#include <bits/stdc++.h>

using namespace std;

//12 21
//12 9
//3 9
//3 6
//3 3
//Phuong phap 1: C�n 
int Gcd1(int a,int b){
	a = abs(a); b = abs(b);
	if(a == 0) return b;
	if(b == 0) return a;
	while(a != b){
		if(a < b) b -= a;
		else a -= b;
	}
	return a;
} 

//a - b nhieu lan = a % b
//Phuong phap 2: mod
/*-----
a   b   r
63 90  63
90 63  27
63 27  9
27 9   0
9  0
-----*/
int Gcd2(int a,int b){
	int r;
	a = abs(a); b = abs(b);
	while(b){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
} 

//Phuong phap 3: De quy
int Gcd(int a, int b){
	return (b == 0) ? a : Gcd(b,a%b);
}
int Gcd3(int a, int b){
	return Gcd(abs(a),abs(b));
} 
/*-------
	Contest Samsung Test
	Cho so ng duong k, va day so a
	Duoc phep giam moi so trong a ko qua k.
	Sua day a de thu duoc Gcd max?
	k = 2 
	a = {17, 8, 91, 115, -1}
	 Gcd(15  6  90  114) = 3 
	Co ngon = Biet cach nau + To chuc nguyen lieu
	Programs = Algorithms + Data Structures 
	NX 1. Gcd(a) <= min(a)
	kiem tra m = mina....1 Neu moi so cua a
	% m <= k 
-------*/

//moi a[i] % d <= k
bool KiemTra(int a[], int n, int d, int k){
	for(int i = 0; i < n; i++){
		if(a[i] % d > k) return false; 
	}
	return true; 
}
int MultiGcd(){
	int a[] = {17, 8, 91, 115, 12, -1};
	int mina = INT_MAX;
	int k = 2;
	int n = sizeof(a) / sizeof(int);
	for(int i = 0; a[i] > 0; i++){
//		cout<<a[i]<<" ";
		if(a[i] < mina) mina = a[i];
	}
//	cout<<mina;
	int d;
	for(d = mina; d > 0; d--){
		if(KiemTra(a,n,d,k)) 
		return d;
	}
}

void TestGcd(){
	int a = -63, b = 81;
	cout<<Gcd2(-a,-b)<<endl;
	cout<<Gcd1(a,b)<<endl;
	cout<<Gcd3(a,b)<<endl;
}

struct Frac{
	int tu;
	int mau;
};

//Boi chung nho nhat
//The least common multiple
int Lcm(int a, int b){
	return a * b / Gcd(a,b);
}

Frac Reduce(Frac x){
	int d = Gcd(abs(x.tu),abs(x.mau));
	x.tu /= d; x.mau /= d;
	return x;
}

Frac Plus(Frac x, Frac y){
	int msc = Lcm(x.mau,y.mau);
	Frac z;
	z.tu = x.tu * (msc / x.mau) + y.tu *(msc/y.mau);
	z.mau = msc;
	return Reduce(z);
}

void Set(Frac &x, int t, int m){
	x.tu = t; x.mau = m;
	
}

void Print(Frac x, const char * msg =""){
	cout<<msg<<x.tu<<"/"<<x.mau;
}
void TestFrac(){
	Frac x,y;
	Set(x,3,7);
	Set(y,1,4);
	Print(x,"\n x = ");
	Print(y,"\n y = ");
	Frac z = Plus(x,y);
	Print(z,"\n z = ");
}
/*----
  Plus(x,y) cong 2 phan so x , y
  1. QDMS
  2. Tu + Tu / msc
  3. Rut gon
----*/ 
main(){
	//int m = MultiGcd();
	//cout<<"\n m =  "<<m;
	TestFrac();
	//cout<<endl<<MultiGcd()<<endl;
	cout<<"\n The End \n";
	return 0;
}
