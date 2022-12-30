// Tom And Jerry
// 17/11/2022
#include<bits/stdc++.h>
using namespace std;
const char * FN = "TOMJERRY.INP"; // input file
const int MN = 256;
char cc[MN]; // cay nhi phan tim kiem

void Go() {
  cout << " ? ";
  fflush(stdin);
  if (cin.get() == '.')
    exit(0);  
}

// Tinh code cua ki tu
int Code(string s) {
  int c = 1;
  for(int i = 0; i < s.length(); ++i)
     c = c*2 + (s[i]-'0') ;
  return c;
}

// Giai ma
void Decode(string s) {
  int c = 1;
  for(int i = 0; i < s.length(); ++i) {
     c = c*2 + (s[i]-'0') ;
     if (cc[c] != '#') {
        cout << cc[c];
        c = 1; // ve goc
     }
  }
}

// input file: 1. ten file 2. Doc duoc
void Run() {
  ifstream f(FN);
  if(f.fail()) {
    cerr << "\n Khong mo duoc input file " << FN;
    exit(1);
  }
  string s;
  int n;
  char ch;
  memset(cc, '#', sizeof(cc));
  f >> n;
  cout << n;
  for(int i = 1; i <= n; ++i) {
    f >> ch >> s;
    // cout << "\n " << ch << ": " << s;
    cc[Code(s)] = ch;
  }
  f >> s;  
  f.close();
  cout << "\n Giai ma: " << s << endl;
  Decode(s);
}

main() {  
  Run();
	cout << "\n T h e   E n d";
	return 0;
}

