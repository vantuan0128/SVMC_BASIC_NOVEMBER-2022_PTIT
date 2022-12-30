// Tap hop, hoan vi, to hop
// 10/11/2022
#include<bits/stdc++.h>

using namespace std;
const char * fn = "PICNIC.INP";
const int MN = 26; 
typedef bitset<MN> CharSet; 

  int n; // so HS
  int m; // so quan he

struct Pair {
   CharSet Left;
   CharSet Right;
};

typedef vector<Pair> VP;

VP q; // chua cac quan he


// day 26 bit 0/1

// Hien thi tap kem chu thich
void Print(CharSet s, const char * msg = "") {
  cout << msg;
  for(int i = 0; i < MN; ++i)
    if (s[i]) cout << char('A'+i);   
}

// Hien thi tap kem chu thich
void Print(Pair x, const char * msg = "") {
  cout << msg;
  Print(x.Left); Print(x.Right, " > ");
}

// Hien thi vector pair kem chu thich
void Print(VP q, const char * msg = "") {
  cout << msg;
  for(int i = 0; i < q.size(); ++i)
     Print(q[i], "\n ");
}

/*-------------------------------------
PICNIC.INP
6 HS 3 quan he
AB > C
.D > E
.E > BF

Find(AD)
ADEBF
3 test
AD nhung ai co mat
E  nhung ai co mat
CD  nhung ai co mat
D   noi F co nghe k?
Ru(D); DEBF
Algorithm 
Lop ABCDEF
CD:  BCDEF
E:   B  EF
AD: ABCDEF
Bac cau: X > Y va Y > Z thi X > z
Gia tang: X > Y va YA > z thi XA >  Z
Phan xa: X > X
input file PICNIC.INP
n m
Kn 1. Co file thi mo va thu doc
Kn. Ban phai biet dang cam gi trong tay
    Giao luu voi ai ?
------------------------------------*/
// A:0 B:1,...
char Ins(CharSet & s, char e) {
  s[e-'A'] = 1;
  return e;
}

// A:0 B:1,...
void Ins(CharSet & s, string str) {
  s.reset(); // xoa cu de nap moi
  for (int i = 0; i < str.length(); ++i)
    Ins(s, str[i]);
}

// kiem tra x <= y
bool IsSubset(CharSet x, CharSet y) {
   // moi a int x co a in y
   return (x & y)  == x;
}

// Hop 2 tap x + y 
CharSet Add(CharSet x, CharSet y) {
  return (x | y);
}
 
// s to chuc . Nhung ai co mat
CharSet Find(CharSet s) {
  // duyet m quan hr
  int c;
  CharSet used;
  while(true) {
     c = 0;
    for(int i = 0; i < m; ++i) {
      //Print(q[i], "\n Xet cap ");
      if (!used[i]) {
        //cout << " Chua dung ";
        if (IsSubset(q[i].Left, s)) {
           s = Add(s, q[i].Right);
           //Print(s, "\n Them duoc ");
           used[i] = 1;
           ++c;        
         } // if
      } // if
    } // for
    if (c == 0) break;
  } // while
  return s;
}

void Read() {
  ifstream f(fn);
  if (f.fail()) {
     cerr << "\n Khon mo duoc input file " << fn;
     exit(1);
  }
  string s;
  Pair p;
  q.clear();
  f >> n >> m;
  cout << n << " HS " << m << " quan he";
  getline(f, s); // new line  
  // doc tiep m pair
  for(int i = 1; i <= m; ++i) {
     getline(f, s); // pair
     // cout << "\n " << s;
     // dua vao ve trai > phai
     int j;
     p.Left.reset(); p.Right.reset();
     for(j = 0; s[j] != '>'; ++j) 
       if (s[j] != ' ') Ins(p.Left, s[j]);
     p.Right.reset();
     for(++j; j < s.length(); ++j) 
       if (s[j] != ' ') Ins(p.Right, s[j]);  
     // Print(p, "\n Pair: ");  
     q.push_back(p); // day m quanhe
  }
   Print(q, "\n Cac pair: ");
   // Test
  int t; // so test
  f >> t;
  getline(f, s); // new line
  cout << "\n " << t << " test.";
  CharSet x;
  for (int i = 1; i <= t; ++i) {
    getline(f, s);
    Ins(x,s);
    cout << "\n Test No << " << i << ". Find of ";
    Print(x); Print(Find(x), " = " );
  }
  f.close();
}

void Picnic() {
  Read(); // AD E CD
}

main() {  
  Picnic();
  //Pair x; // AB > C
  //Ins(x.Left, "AB"); Ins(x.Right, "C"); 
  //Print(x, "\n x: ");
	cout << "\n T h e   E n d";
	return 0;
}

