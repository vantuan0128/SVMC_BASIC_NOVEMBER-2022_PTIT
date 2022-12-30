//Tom And Jerry
//17/11/2022

#include <bits/stdc++.h>

using namespace std;
/*-------------
Chia de tri Divide And Conquer
Cay nhi phan tim kiem toi da 2 nhanh So hoa
-------------*/

const char * fn = "TOMJERRY.INP"; //Input file
const int MN = 256;
char cc[MN]; // cay nhi phan tim kiem

void Go(){
	cout<<" ? ";
	fflush(stdin);
	if(cin.get() == ' . '){
		exit(0);
	}
}
//Tinh code cua ki tu
int Code(string s){
	int c = 1;
	for(int i = 0; i < s.length(); ++i){
		c = c*2 + (s[i]-'0');
		//if(s[i] == '1') c += 1;
	}
	return c;
}

//Giai ma
void Decode(string s){
	int c = 1;
	for(int i = 0; i < s.length(); ++i){
		c = c*2 + (s[i]-'0');
		if(cc[c] != '#'){
			cout << cc[c];
			c = 1; // Ve goc
		}
	}
}
//input file: 1. ten file 2. Doc bang duoc
void Run(){
	ifstream f(fn);
	if(f.fail()){
		cerr << "\n Khong mo duoc input file " << fn;
		exit(1);
	}
	string s;
	int n;
	char ch;
	memset(cc, '#', sizeof(cc));
	f >> n;
	cout << n;
	for(int i = 1; i <= n; ++i){
		f >> ch >> s;
		//cout << "\n "<< ch << ": " << s;
		cc[Code(s)] = ch;
	}
	f >> s;
	f.close();
	cout << "\n Giai ma " << s << endl;
	Decode(s);
}

int main(){
	Run();
	cout<< "\n The End !";
	return 0;
}
