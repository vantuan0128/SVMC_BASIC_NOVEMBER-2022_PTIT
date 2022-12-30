// Divide and Conquer *****
// Quy hoach dong
// Tham
// Quay lui
// Bien doi
#include <bits/stdc++.h>
using namespace std;

int a[] = {7,12,6,5,20,13,2,4,8};
const int MN = 300000;
int b[MN];

/*------------------------
idea: Chia D thanh k phan
xu li tung phan 
Tong hop ket qua
Bo qua nhung phan khong chua nghiem
a) 27 vien bi vang
1 vien loi nhe hon cac vien khac
Dung can thang bang 2 dia AB
can x lan phat hien bi loi?
A B
9 9 9: 1 lan can tim duoc nhom 9 chua loi
3 3 3: 1 lan can tim duoc nhom 3 chua loi
1 1 1: 1 lan can tim duoc nhom 1 chua loi 
      
b) Nhan An Do z = x*y
x    y
33   25

c) Luy thua An Do z = x^y

d) 
------------------------*/


void Print(int a[], int d, int c, const char * msg=""){
	cout<< msg;
	for(int i = d; i <= c; ++i) cout << " " << a[i];
}

void Swap(int a[], int d, int c){
	int tmp = a[d];
	a[d]= a[c];
	a[c] = tmp;
}
//Sap tang mang a[d....c]
//nlog(n) Hoare, n = 1000
//i---|----m----|----j
void QuickSort(int a[], int d, int c){
	int t=d, p=c;
	int m = a[(t+p)/2];
	while(t <= p){
		while(a[t] < m) ++t;
		while(a[p] > m) --p;
		if(t <= p){
			Swap(a , t++ , p--);
			//++t;--p;
		}
	}
	if(d < p) QuickSort(a,d,p);
	if(t < c) QuickSort(a,t,c);
}

void BubbleSort(int a[], int d, int c){
	for(int t = d; t <= c; ++t){
		for(int p = c; p > t; --p){
			if(a[p] < a[p-1]){
				Swap(a , p , p-1);
			}
		}
	}
}

int SecretNum(int d, int c, const char * que){
	char ans;
	int m;
	while(d < c){
		m = (d + c)/2;
		while(true){
			cout << que << m << " [Y|N]: ";
			fflush(stdin);
			ans = toupper(cin.get());
			if(ans == 'Y' || ans == 'N') break;
		}
		if(ans == 'Y') d = m + 1;
		else c = m;
	}
	// d = c
	return d;
}

void Birthday(){
	int month = SecretNum(1,12,"Ban sinh sau thang ");
	int day = SecretNum(1,31," * Ban sinh sau ngay ");
	cout << "\n Your Birthday is " << day << " / " << month;
}

void Test(){
	int d = 0, c = sizeof(a)/sizeof(int) - 1;
	Print(a,d,c,"\n a: ");
	QuickSort(a,d,c);
	//BubbleSort(a,d,c);
	Print(a,d,c,"\n Sorted a: ");	
}

void Gen(int x[], int n){
	srand(time(NULL));
	for(int i = 0; i < n; ++i){
		x[i] = rand() % MN;
	}
}

//So sanh QuickSort va BubbleSort
void Test2(){
	int c = MN-1;
	int d = 0;
	Gen(b , c+1);
	Print(b,0,20,"\n Init b: "); Print(b,c-20,c);
	QuickSort(b,d,c);
	Print(b,0,20,"\n QSorted b: "); Print(b,c-20,c);
	cout << "\n End of Q sort";
	
	Gen(b , c+1);
	Print(b,0,20,"\n Init b: "); Print(b,c-20,c);
	BubbleSort(b,d,c);
	Print(b,0,20,"\n BSorted b: "); Print(b,c-20,c);
	cout << "\n End of B sort";
}

main(){
	//int x = SecretNum(1,100); // 65
	//cout << "\n Your secret number is " << x;
	Birthday();
	//Test();
	//Test2();
	cout<<"\n T h e E n d";
	return 0;
}
