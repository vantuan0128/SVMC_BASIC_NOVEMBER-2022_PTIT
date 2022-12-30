// Hoan vi thu k
#include<bits/stdc++.h>
using namespace std;

const int MN = 16; // max N
int fac[MN]; // cac giai thua
bitset<MN> elem; // danh dau cac elem

void Go() {
  cout << " ? ";
  fflush(stdin);
  if (cin.get() == '.') 
    exit(0);
}

// khoi tri cho cac giai thua n!, 1 <= n <= 15
void SetFac() {
  fac[0] = 1;
  for (int i = 1; i < MN; ++i) {
    fac[i] = fac[i-1]*i ;
  }
}

// set elem = day bit 1
void SetElem(int n) {  
  for (int i = 0; i < n; ++i) 
    elem[i] = 1;
}

// tim tong so bit 1 = group
char GetElem(int n, int group) {
  int d = -1, i = -1;
  while(d < group) {
    d += elem[++i];
  }
  elem[i] = 0;
  return char('A'+i);
}

// Tim hoan vi thu k trong n! hoan vi
string Permutation(int n, int k) {  
   int group;
   SetElem(n);
   string s = "";
   for(int i = n-1; i > 0; --i) {
     group = k / fac[i];
     k %= fac[i];
     s += GetElem(n, group); 
   }
   s += GetElem(n, k); 
   return s;   
 }

// ki tu e thuoc group nao ?
char GetGroup(char e) {
  int d = 0, id = int(e-'A');    
  for(int i = 0; i < id; ++i) {
    d += elem[i];
  }
  elem[id] = 0;
  return d;
}

// Xac dinh thu tu cua hoan vi p
int Index(string p) {
   int n = p.length();
   SetElem(n);
   int group;   
   int k = 0;
   for(int i = 0; i < n-1; ++i) {
     group = GetGroup(p[i]);     
     k += fac[n-1-i]*group;
   }
  return k;
}

void Run() {
  SetFac();  
  string s;
  int j;
  int n = 5;
  for (int i = 0; i < fac[n]; ++i) {
    s = Permutation(n, i); // s = hoan vi thu i
    j = Index(s); // s la hoan vi thu j
    cout << "\n " << i << ". " << s << " -> " << j;
    if (i == j) cout << " CORRECT.";
      else {
        cout << " ERRROR.";
        Go();    
      }    
  }  
}

main() {  
   Run();
  int n = 5;
  SetFac();
  string s = Permutation(n,80);
  cout << "\n s = " << s; 
  cout << "\n " << Index("DBCAE");
  cout << "\n T h e   E n d";
	return 0;
}

