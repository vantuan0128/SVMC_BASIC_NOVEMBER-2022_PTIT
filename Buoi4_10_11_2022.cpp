//Tap hop, hoan vi, to hop
// 10/11/2022
#include <bits/stdc++.h>

using namespace std;
const char * fn = "PICNIC.INP";
const int MN = 26;
typedef bitset<MN> CharSet;
struct Pair{
	CharSet Left;
	CharSet Right;
};

typedef vector<Pair> VP;

int n; // So HS
int m; // So quan he

VP q; // Chua cac quan he

//day 26 bit 0/1

//Hien thi tap kem chu thich
void Print(CharSet s, const char * msg = ""){
	cout << msg;
	for(int i = 0; i < MN; i++){
		if(s[i]) cout <<(char) ('A'+ i);
	}
}

//Hien thi tap kem chu thich
void Print(Pair x, const char * msg = ""){
	cout << msg;
	Print (x.Left); Print(x.Right, " > ");
}

//Hien thi vector pair kem chu thich
void Print(VP q, const char * msg = ""){
	cout << msg;
	for(int i = 0; i < q.size(); i++){
		Print(q[i],"\n");
	}
}

/*------------
PICNIC.INP
6 HS 3 quan he
AB > C
.D > E
.E > BF

Find(AD)
ADE
3 test
AD nhung ai co mat
E nhung ai co mat
CD nhung ai co mat
D NOI F CO NGHE KHONG ?
Ru(D): DEBF
Algorithm
Lop ABCDEF
CD:  BCDEF
E:   B  EF
AD: ABCDEF  
Bac cau: X > Y va Y > Z thi X > Z
Gia tang: X > Y va YA > Z thi XA > Z
Phan xa: X > X
input file PICNIC.INP
n m
KN 1. Co file thi mo va thu doc
KN 2. Ban phai biet dang cam gi trong tay
	  Giao luu voi ai ?
------------*/

//A: 0 B:1 ..... 
char Ins(CharSet &s, char e){
	s[e-'A'] = 1;
	return e;
}

void Ins(CharSet &s, string str){
	s.reset(); // xoa cu dep nap moi
	for(int i = 0; i < str.length(); i++){
		Ins(s,str[i]);
	}
}

// kiem tra x <= y
bool IsSubset(CharSet x, CharSet y){
	//moi a int x co a in y
	return (x & y) == x;
}

// Hop 2 tap x + y
CharSet Add(CharSet x, CharSet y){
	return (x | y);
}

// s to chuc . Nhung ai co mat
CharSet Find(CharSet s){
	//duyet m quan he
	int c;
	CharSet used;
	while(true){
		c = 0;
		for(int i = 0; i < m; i++){
			//Print(q[i], "\n Xet cap ");
			if(!used[i]){
				//cout<<" Chua dung ";
				if(IsSubset(q[i].Left,s)){
					s = Add(s,q[i].Right);
					//Print(s,"\n Them duoc ");
					used[i] = 1;
					++c;				
				} //if trong	
			} // if ngoai	
		}
		if(c == 0) break;		
	} //while
	return s;
}
void Read(){
	ifstream f(fn);
	if(f.fail()){
		cerr << "\n Khong mo duoc input file "<<fn;
		exit(1);
	}
	string s;
	Pair p;
	q.clear();
	f >> n >> m;
	cout << n <<" HS " << m << " quan he ";
	getline(f,s); // new line
	// doc tiep m pair
	for(int i = 1 ; i <= m; i++){
		getline(f,s); // pair 
		cout << "\n"<< s;
		// Dua vao ve trai, phai
		int j;
		p.Left.reset(); p.Right.reset();
		for(j = 0; s[j] != '>'; j++){
			if(s[j] != ' ') Ins(p.Left,s[j]);
		}
		p.Right.reset();
		for(++j; j < s.length(); j++){
			if(s[j] != ' ') Ins(p.Right,s[j]);
		}
		//Print(p,"\nPair: ");
		q.push_back(p); // Day m quan he
	}
	Print(q,"\nCac pair: ");
	int t; // so test
	f >> t;
	getline(f,s);
	// new line
	cout<< "\n"<<t<<" test.";
	CharSet x;
	for(int i = 1; i <= t; i++){
		getline(f,s);
		Ins(x,s);
		cout<<"\nTest No "<<i<<". Find of ";
		Print(x); Print(Find(x)," = ");
	}
	f.close();
}

void Picnic(){
	Read();
}

main(){
	Picnic();
//	Pair x; // AB > C
//	Ins(x.Left,"AB"); Ins(x.Right,"C");
//	Print(x,"\n x: ");
	cout<<"\n The End !!! ";
	return 0;
}
