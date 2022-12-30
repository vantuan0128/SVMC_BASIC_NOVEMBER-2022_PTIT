/*************************************
   E48. Self powers 
		Answer: 9110846700
		Time = 0.012 sec.
*************************************/
#include <iostream>
 
using namespace std;

typedef unsigned long long UL;	
	
const UL m = 10000000000; // 10G

#define Plus(a,b) ((a >= m-b) ? a-(m-b) : (a+b));
 
// z = ab mod m
UL Mult(UL a, UL b) {
	UL z = 0;
	while (a > 0) {
		if (a & 1) // a is odd
		 	z = Plus(z,b); // z = (z+b) mod m
		a >>= 1; // a = a div 2
		b = Plus(b,b); // b = 2b mod m
	} // while
	return z;	
}
 
// z = a^k mod m
UL Exp(UL a, int k) {
	UL z = 1;
	while (k > 0) {
		if (k & 1) // k is odd
		 	z = Mult(z,a); // z = (z*a) mod m
		k >>= 1; // k = k div 2
		a = Mult(a,a); // a = a*a mod m
	} // while
	return z;	
} // Exp

void E48(int n) {
 	UL sum = 1; // sum = 1^1 
 	for (int x = 2; x <= n; ++x) 
 	  	if (x % 10) 
 		   sum = Plus(sum, Exp(x,x)); 
		   // sum = sum + Exp(x,x)
 	cout << "\n " << sum;
} // E48
  
main() {
  	E48(1000); // 9110846700
	//----------------------------     
  	cout << "\n T H E   E N D.";
  	return 0;       
} // main

