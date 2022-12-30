// Divide And Conquer *****
// Quy hoach dong
// Tham
// Quay lui
// Bien doi
#include<bits/stdc++.h>
using namespace std;

/*------------------------------
 idea: chia D thanh k phan
 xu li tung phan
 Tong hop ket qua
 Bo qua nhung phan khong chua nghiem
a) 27 vien bi vang, 
1 vien loi nhe hon cac vien khac.
Dung can thang bang 2 dia AB 
can x lan phat hien bi loi?
A B  
9 9 9: 1 lan can tim duoc nhom 9 chua loi
3 3 3: 1 lan can tim duoc nhom 3 chua loi
1 1 1: 1 lan can tim duoc nhom 1 chua loi

b) Nhan An Do z = x*y
x    y
33  25  

c) Luy thua An Do z = x^y

d) 

--------------------------------*/

/*--------------------------------------------
   Doan sinh nhat: co the hoi ko qua 9 cau Y/N
   doan duoc SN?
   chia 2
   Thang: 1..12
   Ngay: 1..31   
   --------------------------------------------*/
   /* ---------------------------------------------
   Doan so: nghi so x : d..c
   Y/N 1..365  Log(n)
   d----|---|-----m-------------c 
               x > m
   -------------------------------------------------*/
   int SecretNum(int d, int c, const char * que) {
      char ans;
      int m;
      while(d < c) {
        m = (d+c) / 2;
        while(true) {
          cout << que << m << " [Y|N]: ";
          fflush(stdin);
          ans = toupper(cin.get());
          if (ans == 'Y' || ans == 'N') break;
        }        
        if (ans == 'Y') d = m+1;
        else c = m;
      } 
      // d = c
      return d;
   }
   
   void Birthday() {
     int month = SecretNum(1,12, "Ban sinh sau thang ");
     int day = SecretNum(1,31, " * Ban sinh sau ngay ");
     cout << "\n Your Birthday is " << day << " / " << month;  
   }
   
main() {  
  //int x = SecretNum(1,100); // 65
  // cout << "\n Your Secret number is " << x;
  Birthday();
	cout << "\n T h e   E n d";
	return 0;
}

