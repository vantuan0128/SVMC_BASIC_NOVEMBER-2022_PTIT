// FIBAB
#include<bits/stdc++.h>

using namespace std;
const int MN = 91;
typedef long long Long;
Long len[MN];

void GetLen() {
  len[1] = len[2] = 1;
  for(int i = 2; i < MN; ++i) 
     len[i] = len[i-2]+len[i-1];
  //for(int i = 1; i < MN; ++i) 
    //cout << "\n " << len[i];

}

// Ki tu thu k trong FIBAB thu n
// F(n) -----len(n-2)------|-----len(n-1)-------
char FibAB(int n, int k) {
  while(n > 2) { 
   if (k <= len[n-2]) {
      n -= 2;      
    }
    else { k -= len[n-2]; n -= 1; }
  }
 return (n == 1) ? 'A':'B';      

}
 
main() {
  GetLen();
  int n = 17;
  for (int i = 1; i <= len[n]; ++i) 
     cout << FibAB(n, i);
	cout << "\n T h e   E n d";
	return 0;
}

