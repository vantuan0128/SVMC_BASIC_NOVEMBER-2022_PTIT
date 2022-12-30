//Thay Nguyen Xuân Huy
//gmail : nxhuy564@gmail.com
//sdt: 0903203800

// Dev c++ ma nguon mo
// Cau truc chuong trinh c
// Dat thu vien va moi truong lam viec
#include <bits/stdc++.h> // thu vien chuan

using namespace std; //Vung lam viec chuan

const char* fn = "NUM.INP";

/*---------
	Homework
	So ngu giac P(n) = n(3n-1)/2
	x la so ngu giac thu n?
	0, 1, 5, 12, 22
	x = n(3n-1)/2
	2x = n(3n-1) = 3n^2 - n
	3n^2 - n - 2x = 0 tim n ?
	delta = 1 + 24x can
	n = (1 + can(delta))/6 phai la so tu nhien
	So luc giac H(n) = n(2n-1)
	0, 1, 6, 28, ....
	Tim n de P(n) = x?
	Tim n de H(n) = x?
----------*/
//Cac ham

// IBM Ky nghe phong sach Clean Room
// 1. The empty room is clean
// 2. Write only one command / Test

// Tai su dung Reusing

void Go(){
	cout<<" ? ";
	fflush(stdin);
	if(cin.get()=='.'){
		exit(0);
	}
}

//So tam giac (triangle)
//Cho x? hoi x co la so tam giac khong?
//x la So tam giac thu n
//-->Tim n de T(n) = x
// T(1)=1, T(1)=1+2=3, T(3)=1+2+3=6, T(4)=10, T(5)=15...
// T(n) =  x = n*(n+1)/2 -> 2x = n(n+1)
// n = sqrt(2x);

int Triangle(int x){ // Tim n de T(n) = x
	int xx = x+x; //2x
	float n = (int) sqrt(xx);
	return (n*(n+1) == xx) ? (int) n : -1;
}

int Triangle2(int x){ // Tim n de T(n) = x
	int n = 0;
	int y = 0;
	while(y < x){
		++n;
		y += n;
	}
	return (y == x) ? n : -1;
}

void Ans(int x){
	int n = Triangle(x);
	if(n>=0){
		cout<<"\n"<<x<<" la so tam giac thu "<<n;
	}
	else cout<<"\n"<<x<<" khong la so tam giac";
}
// Phuong an 1: input from keyboard
void Run1(){
	int x,n;
	while(true){
		cout<<"\n x = ";
		fflush(stdin); // Lau input buffer
		cin >> x;
		if(x < 0) break;		
		Ans(x); 
	}
}
//Phuong an 2: Day du lieu co san
void Run2(){
	int a[] = {499500,10,17,45,55,67,1023};
	int n = sizeof(a) / sizeof(int);
	for(int i = 0;true; ++i){
		if(a[i] < 0) break;
		Ans(a[i]);
	}
}

//Phuong an 3: Nap tuy bien qua string
void Run3(string s){
	stringstream ss;
	ss << s;
	int x, n;
	while(true){
		ss >> x;
		if(x < 0) break;
		Ans(x);
	}
}

//Phuong an 4: Nap tu file
void Run4(){
	ifstream f(fn); // Mo file de doc
	if(f.fail()){
		cerr<"\n Khong mo duoc input file "<<fn;
		exit(1);
	}
	int x,n;
	while(true){
		f >> x;
		if(x < 0) break;
		Ans(x);
	}
	f.close();
}
//phong khach san khau
main(){ 
//	Run1(); Go();
//	Run2(); Go();
//	Run3("499500 10 17 45 55 67 1023 -1"); Go();
	Run4(); Go();
	return 0;
}
