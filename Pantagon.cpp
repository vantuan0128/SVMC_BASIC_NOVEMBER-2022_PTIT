// So Ngu giac (Pentagon Number)
#include<bits/stdc++.h>

using namespace std;

const char * FN = "NUM.INP";
const string NGU_GIAC = " la so ngu giac thu ";
const string KO_NGUGIAC = " khong la so ngu giac.";

// x la so tam giac thu n
// x = n(3n-1) / 2
// 3n^2 - n - 2x = 0
// delta = 1 + 24x
// n = (1 + can(delta)) / 6
int Pentagon(int x) {  
  if (x == 0) return 0;
  double n = (1 + sqrt(1+24*x))/6;
  return ((int)n == n) ? n : -1;
}

/*----------------------------
   Hexagon x = n(2n-1)
   2n^2 - n - x = 0
   delta = 1 + 8x
   nghiem n = (1 + Can(1+8x)) / 4
----------------------------*/
void Ans(int x) {
  cout << "\n " << x;
  int n = Pentagon(x);
  if (n > -1) 
    cout << NGU_GIAC << n;
  else  cout << KO_NGUGIAC;  
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
  // n(3n-1) / 2
  //RunString("0 1 10 12 44 14950 -1");
  // RunArray();
  // RunFile();
  RunConsole();
	cout << "\n T h e   E n d";
	return 0;
}

