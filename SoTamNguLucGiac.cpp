// Scrolling number
#include<bits/stdc++.h>

using namespace std;

const char * fn = "SCROLL.INP";

// chuyen char sang int
#define Num(ch) (ch) - '0'

const string DIGIT = "0123456789";

// Scrolling number
int S(const string &s) {
  int h = 0;
  // tinh do cao h
  for (int i = 0; i < s.length(); ++i) {
    h += Num(s[i]);
  }
  return h % 9;
}

// tang them s mot luong d 
// de thu duoc so chia het cho 9
void Inc(string &s, int d) {      
   int sonho = d, tong;
   for (int i = s.length()-1; i >= 0; --i) {
	    tong = Num(s[i]) + sonho;
	    sonho = 0;
	    if (tong >= 10) {
	      sonho = 1;
	      tong -= 10;
	    } 
	    s[i] = DIGIT[tong];
	    if (sonho == 0) return;
	 } // for 
	 if (sonho > 0) 
	   s = DIGIT[sonho] + s;
}

void Run() {
  ifstream f(fn);
  if (f.fail()) {
    cerr << "\n Khong mo duoc input file " << fn;
    exit(1);
  }  
  string line;
  int s;
  while (true) {
     getline(f, line);
	    cout << "\n " << line;
	    if (line == "-1") break;
	    s = S(line);
	    cout << " scroll = " << s;
	    if (s == 0) cout << " khong them "; 		 
	    else { 
		Inc(line, 9-s); 
		cout << " them " << 9-s; 		 
	     }
	     cout << " -> " << line; 		 
   }
   f.close();
 } 

main() {  
  Run();
	cout << "\n T h e   E n d";
	return 0;
}

