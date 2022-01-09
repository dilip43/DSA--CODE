#include<bits/stdc++.h>
using namespace std;
#include "Fraction.cpp"

int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);


	Fraction const f3;
	// cout << f3.getNumerator()<<" "<<f3.getDenominator()<<endl;
	// f3.print();

	Fraction f4=f1+f2;
	f1.print();
	f4.print();
	Fraction f5=f1*f2;
	f5.print();

	return 0;
}