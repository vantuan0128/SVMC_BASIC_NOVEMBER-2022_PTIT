//Palindrome
//Dynamic Programming: Quy hoach dong
/*---------------
- QHD la bai toan ma buoc thu i dua 
vao cac buoc truoc hoac sau i
- So do
	1. He thuc QHD: Phuong trinh Bellman
	2. Lap trinh de quy small data
	3. Cai tien I, II. 
	I. Dung mang 2 chieu Vi sao lau? Goi cung 1 ham nhieu lan
	II. Dung 2 mang 1 chieu
	Moi ham khong qua 1 lan
	Dung mang ghi lai gia tri P(i,j)
1. P(i,j) la length pal string dai nhat khi xet s[i...j]
	s = baeadbadb Len(s) = 1000
Dap so = len(s) - P(s,0,len(s)-1)
P(0,0) = 1		P(3,6) = 3	
P(0,1) = 1		P(4,8) = 3
P(0,2) = 1
P(0,3) = 3
Cac tinh chat cua ham P
P(i,i) = 1
P(i,j) = 0 , i > j (quy uoc)
i < j: 
--a(----------)a----- P(i,j) = P(i+1,j-1) + 2
--a(----------)b----- P(i,j) = P(i+1,j-1) + 2
max(P(i+1,j), P(i,j-1))
P(i,i) = 1
P(i > j) = 0
i < j: 
    s[i] = s[j] P(i,j) = P(i+1,j-1) + 2
    s[i] != s[j] P(i,j) = max(P(i+1,j), P(i,j-1))
----------------*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1001;
int p[MN][MN];
string s;
int d; // so lan goi

int P(int i, int j){
	++d;
	if(i > j) return 0;
	if(i == j) return 1;
	// i < j
	if(s[i] == s[j]) return P(i+1,j-1) + 2;
	else return max(P(i+1,j), P(i,j-1));
}

//So ki tu can xoa khoi s de thu duoc Pal
int Pal(string ss){
	s = ss;
	cout<<s.length()<<endl;
	int n = s.length();
	d = 0;
	return n - P(0,n-1);
}

int PalI(string ss){
	s = ss;
	cout<<s.length()<<endl;
	int n = s.length();
	memset(p,0,sizeof(p));
	//cheo chinh 1
	for(int i = 0; i < n; ++i){
		p[i][i]=1;
	}
	//dien mang tu duoi len tren
	for(int i = n-2; i >=0; --i){
		for(int j = i+1; j<n; ++j){
			p[i][j] = (s[i] == s[j]) ? p[i+1][j-1] + 2
						: max(p[i+1][j],p[i][j-1]); 
		}
	}
	return n - p[0][n-1];
}

int main(){
	cout << PalI("abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba");
	cout << "\n T h e E n d";
	return 0;
}
