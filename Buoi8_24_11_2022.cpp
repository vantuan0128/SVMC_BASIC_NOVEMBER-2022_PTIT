/*
	Name: Buoi8_24_11_2022
	Copyright: (C) 2022
	Author: Nguyen Van Tuan
	Date: 24/11/22 19:46
	Description: Find the last ten digits of sum
	s = 1^1 + 2^2 + 3^3 + ... + 1000^1000
	Algorithm: mod 1G,, Tranh tran so (value over)
*/


#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long Long; //len = 18
const Long M = 10000000000; // 10G = 10000000000


void Go(){
	cout<<" ? ";
	fflush(stdin);
	if(cin.get()=='.'){
		exit(0);
	}
}

// Modulo Arithmetics
// z = (a + b) mod 1G
// a > M-b
// M = 100
// (98+99) % 100 98+99-100 = 98 - (100-99) 97

Long Add(Long a, Long b){
	return (a >= M-b) ? a - (M-b) : a+b;
}

void Run(){
	cout << Add(98,99);
}

// z = (a * b) % M
Long Mult(Long a, Long b){
//	Muc a = 33 gao loai b = 25L vao thung z // z = ab
//			16				50		25
//			8				100
//			4				200
//			2				400
//			1				800
//			33*25 = 825
	Long z = 0;
	while(a > 0){
		if(a & 1) z = Add(z,b); // z = (z + b) % M;
		a >>= 1; // a = a / 2;
		b = Add(b,b); //b = 2b % M;
	}
	return z;
}

// z = a^b mod M
// a^(2k) = (a^2)^k
// a^(2k+1) = aa^(2k) = a(a^2)^k
Long Exp(Long a, Long b){
	Long z = 1;
	while(b > 0){
		if(b&1) z = Mult(z,a); // z = z*a % M
		b >>= 1; // b = b / 2;
		a = Mult(a,a); // a = a*a % M
	}
	return z;
}

//1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317
void Test(){
	Long s = 0;
	for(int x = 1; x <= 1000; ++x){
		if(x%10) s = Add(s,Exp(x,x));
	}
	//dap an 9110846700
	cout << s; //71317
}

int main(){
	//Run();
	Test();
	cout <<"\n T h e E n d !";
	return 0;
}
