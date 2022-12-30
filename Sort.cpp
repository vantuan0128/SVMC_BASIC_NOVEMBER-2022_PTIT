#include<bits/stdc++.h>
using namespace std;

int a[] = {7, -2, -9, 90, 88, 4, 22, 11, 2, 4, 12, 6, 5, 20, 2,  13, 2, 4, 8}; 
const int MN = 300000;
int b[MN];

void Print(int a[], int d, int c, const char * msg = "") {
  cout << msg;
  for (int i = d; i <= c; ++i) 
     cout << " " << a[i];
}

void Swap(int a[], int i, int j) {
    int x = a[i]; a[i] = a[j]; a[j] = x;
}

// sap tang mang a[d..c]
// Hien thi mang a[d..c] kem chu thichs
// nlog(n) Hoare, n = 1000 T = 10^4
// i---(i)i-----m----j(j)------j
void QuickSort(int a[], int d, int c) {
  int t = d, p = c;
  int m = a[(t+p)/2];
  while (t <= p) {
    while(a[t] < m) ++t;
    while(a[p] > m) --p;
    if (t <= p) {
      Swap(a, t++, p--);
      // ++t; --p;
    }
  }
  if (d < p) QuickSort(a, d, p);
  if (t < c) QuickSort(a, t, c);  
}

void BubbleSort(int a[], int d, int c) {
  for(int t = d; t <= c; ++t)
     for(int p = c; p > t; --p) 
        if (a[p] < a[p-1]) 
           Swap(a, p, p-1);
}

void Test() {
  int d = 0, c = sizeof(a)/sizeof(int) - 1;
  Print(a, d, c, "\n a: ");
  QuickSort(a, d, c);
  //BubbleSort(a, d, c);
  Print(a, d, c, "\n Sorted a: ");
}

void Gen(int x[], int n) {
   srand(time(NULL));
   for(int i = 0; i < n; ++i)
      x[i] = rand() % MN;
}

// So sanh QuickSort va BubbleSort
void Test2() {
  int c = MN-1;
  int d = 0;
 
  Gen(b, c+1);
  Print(b,0,20, "\n Init b: "); Print(b,c-20,c); 
  QuickSort(b,d,c);
  Print(b,0,20, "\n Qsorted b: " ); Print(b,c-20,c); 
  cout << "\n End of Q sort";
  
  Gen(b, c+1);
  Print(b,0,20, "\n Init b: "); Print(b,c-20,c); 
  BubbleSort(b,d,c);
  Print(b,0,20, "\n B sorted b: " ); Print(b,c-20,c);   
  cout << "\n End of B sort";
}

main() {  
  // Test();
  Test2();
	cout << "\n T h e   E n d";
	return 0;
}

