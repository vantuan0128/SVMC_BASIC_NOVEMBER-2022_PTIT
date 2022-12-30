// so nguyen to
// Tue 8 Nov 2022
/**************************************
  DN n > 1 co dung 2 uoc
  2 3 5 7 11 13 17 19 23 29 31 ... 97
  Liet ke cac so nt < n
  Sang Eratosthenes 
  del 1
  tiep theo chua del i ng to
  xoa cac boi cua i ke tu i*i
  

**************************************/

#include <bits/stdc++.h>

using namespace std;
const int MN = 1000000; // 2M
bitset<MN> s; // sang
const int POW[] = {10, 100, 1000, 10000, 100000, 1000000};
const int BADDIG[] = {0,0,0,0,1,0,1,0,1,0} ; //04568

// cac so ng to < n
int Sieve(int n) {
  for (int i = 2; i < n; ++i) s[i] = 1; // gan moi bit 1
  s[0] = s[1] = 0; // del 0, 1
  // del cac boi cua 2 ke tu 4
  for(int j = 4; j < n; j += 2) s[j] = 0;
  int sn = (int)sqrt(n);
  for (int i = 3; i <= sn; i += 2) {
     if (s[i]) {
       for (int j = i*i; j < n; j += i)
          s[j] = 0;
     }
  }  
  return s.count();
}

// sinh cac so ng to ghi file, 
int Sieve(int n, const char * fn ) {
  int m = Sieve(n);
  ofstream f(fn);
  f << 2 << endl;
  for (int i = 3; i < n; i += 2)
     if (s[i]) f << i << endl;
  f.close();   
}

void Run() {
  int n = 700;
  int m = Sieve(n);
  if (s[2]) cout << 2;
  for (int i = 3; i < n; i += 2)
    if (s[i]) cout << " " << i;
  cout << "\n Total " << m;
}

/*-------------------------------------------
  Liet ke 11 so nguyen to cat duoc < 1M 
  7578|7 Euler Project
  Sieve(1M)
  AllCut #x - 1 nhat tao a|b deu trong sang
  Mat ma voi khoa cong khai  
  Alain Turing Tunscatable
  loai 04685
--------------------------------------------*/
bool OldAllCut(int x) {
  // 12345 a = x % 100; b = x / 100
  // 53
  int m = 10, a, b;
  while (m < x) { 
     a = x % m; 
     if (s[a] == 0) return false;
     b = x / m;
     if (s[b] == 0) return false;
     m *= 10;
  }
  return true;
}

bool AllCut(int x) {
  for(int i = 0; POW[i] < x; ++i) {       
     if (s[x % POW[i]] == 0) return false;
     if (s[x / POW[i]]== 0) return false;
  }
  return true;
}

bool Good(int x) {
  while(x) {
    if (BADDIG[x % 10]) return false;
    x /= 10;
  }
  return true;
}

void Cut(int n) {
  Sieve(n);
  for(int i = 3; i < 60; i += 2) 
     if (s[i]) cout << " " << i;
  for(int i = n-50; i < n; ++i) 
     if (s[i]) cout << " " << i;
  int c = 0; 
  cout << endl;
  for (int p = 23; p < n; p += 2) {
     if (s[p]) { // p nguyen to 
       if (Good(p)) {
         if (AllCut(p)) {
           cout << " " << p;
            c++;
          } // if
        } // if Good 
     } // if
  } // for
  cout << "\n Total: " << c;
}

main() {
  Cut(MN);
  // cout << Good(12397);  // Run();
  //Sieve(1000000, "PIME1M.DAT");
  // 23 + 37 + 53 + 73 + 313 + 317 + 373 
  //         + 797 + 3137 + 3797 + 739397 


	// --------------------------------
    cout << endl << "\n\n T h e   E n d \n";
    return 0;
}

