/***********************************************
  3/11/22 Bai 2. So hoc (Arithmetic)
  Gcd, Lcm, Day uoc dhung lon nhat, cong phan so
  
  On bai bai 1
    So tam giac
    So Ngu giac
    So luc giac
    Ghi nho: 1. Ky nghe phong sach Empty 1/test
             2. Dong quy: quy ve mot moi
             3. Tay nao
             4. Name: goi nho Thong nhat
             Ten ham: Viet Hoa chu cai dau
             5. Hau het SV ko biet test
*************************************************/
// So tam giac (Triangle Number)
#include<bits/stdc++.h>

using namespace std;

const char * FN = "NUM.INP";
const string TAMGIAC = " la so tam giac thu ";
const string KOTAMGIAC = " khong la so tam giac.";

// x la so tam giac thu n
// 2x = n(n+1)
int Triangle(int x) {
  int xx = x + x; // 2x = n(n+1)
  int n = sqrt(xx);
  return (n*(n+1) == xx) ? n : -1;
}

void Ans(int x) {
  cout << "\n " << x;
  int n = Triangle(x);
  if (n > -1) 
    cout << TAMGIAC << n;
  else  cout << KOTAMGIAC;  
}

// Nhap lieu tu ban phim
void RunConsole() {
  int x;
  while(true) {
    cout << "\n x = "; 
    cin >> x;
		if (x < 0) break;
		Ans(x);
  }
}

// Nhap lieu tu mang
void RunArray() {
  int a[] = {6, 18, 0, 1, 31, 15, 4950, -1};
  for(int i = 0; a[i] >= 0; ++i) 
    Ans(a[i]);
}

// Nhap lieu tu stringstream
void RunString(string s) {
  cout << "\n Input " << s;
  stringstream ss(s);
  int x;
  while(true) {
    ss >> x;
    if (x < 0) break;
    Ans(x);
  }
}

// Nhap lieu tu file
void RunFile() {
  ifstream f(FN);
  int x;
  while(true) {
    f >> x;
    if (x < 0) break;
    Ans(x);
  }
  f.close();
}

main() {  
  // RunString("0 1 3 6 15 21 28 4950 -1");
  // RunString("61 18 11 17 31 19 4953 -1");
  // RunString("4950 61 3 17 6 -1");
  
  RunArray();
  // RunFile();
  // RunConsole();
	cout << "\n T h e   E n d";
	return 0;
}

