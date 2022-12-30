// Palindrome
#include<bits/stdc++.h>

using namespace std;
const int MN = 1001;
int p[MN][MN];
string s;



int P(int i, int j) {
  if (i > j) return 0;
  if (i == j) return 1;
  // i < j
  return (s[i] == s[j]) ? P(i+1,j-1) + 2
         : max(P(i, j-1), P(i+1, j));  
}

// so ki tu can xoa khoi s de thu duoc Pal
int Pal(string ss) {
  s = ss;
  cout << s.length() << endl;
  int n = s.length();
  return n - P(0,n-1);
}

// Cai tinen lan I
int PalI(string ss) {
  s = ss;
  cout << s.length() << endl;
  int n = s.length();
  memset(p, 0, sizeof(p));
  // cheo chinh 1
  for(int i = 0; i < n; ++i) p[i][i] = 1;
  // dien mang tu duoi len
  for(int i = n-2; i >= 0; --i) {
     for(int j = i+1; j < n; ++j) {
        p[i][j] = (s[i] == s[j]) ? p[i+1][j-1] + 2
                   : max(p[i][j-1], p[i+1][j]);   
     }
  }
  return n - p[0][n-1];
}

main() {
  cout << PalI("1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a1abc2abc3deed4cb5acb6a");     
	cout << "\n T h e   E n d";
	return 0;
}

