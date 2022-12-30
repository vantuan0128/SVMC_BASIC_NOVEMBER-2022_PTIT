// Devc++ ma nguon mo
// So tam giac (Triangle)
// Cho x ? x la so tam giac ?

#include<bits/stdc++.h> // thu vien chuan
using namespace std; // vung lam viec chuan

// IBM Ky nghe phong sach Clean Room
// 1. Phong rong thi sach
// 2. Moi lan chi nap 1 lenh / Test 
// Tim n de T(n) = x?
// T(n) = x = n(n+1)/2 -> 2x = n(n+1)  
int Triangle(int x) { // Tim n de T(n) = x
  int xx = x+x; // 2x
  float n = (int)sqrt(xx); // can 10 
  return (n*(n+1) == xx) ? (int)n : -1;
}

// Phuong an 1: input from key board
void Run1() {
  int x, n;
  while(true) {
    cout << "\n x = ";
    fflush(stdin); 
    cin >> x;
    if (x < 0) break;
		n = Triangle(x);
		if (n >= 0)
		   cout << "\n " << x << " la so tam giac thu " << n; 
		else cout << "\n " << x << " khong phai so tam giac";   
  }
}

// Nap day du lieu co san trong mang
void Run2() {
  int a[] = {499500, 10, 17, 45, 55, 67, 1023, -1}; 
  //int n = sizeof(a) / sizeof(int);
  for (int i = 0; true; ++i) {
    if (a[i] < 0) break;
    int m = Triangle(a[i]);
    cout << "\n " << a[i];
		if (m >= 0) cout << " la so TG thu " << m;
		else cout << " khong phai so TG.";
	} // for
} // Run2

// Nap tuy bien qua string
void Run3(string s) {
  stringstream ss;
  ss << s;
  int x, n;
  while (true) {
    ss >> x;
    if (x < 0) break;
    n = Triangle(x);
    cout << "\n " << x;
		if (n >= 0) cout << " la so TG thu " << n;
		else cout << " khong phai so TG.";		  
  }  
} // Run3

// nap tu file
void Run4() {

}

// phong khach san khau
main() {  
  Run3("17 10 45 499500 69 21 1023 55 67 -1");
	cout << "\n T h e   E n d";
	return 0;
}

