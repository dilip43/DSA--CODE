#include<bits/stdc++.h>
using namespace std;

class complexNumber {
private:

	int real;
	int imaginary;

public:

	complexNumber(int real, int imaginary) {
		this.real = real;
		this.imaginary = imaginary;
	}

	void print() {
		cout << real << "+" << imaginary << i << endl;
	}

	void plus(complexNumber const &c2){

	}

	void multiply(complexNumber const &c2){

	}
}

int main() {
	int real1, imaginary1, real2, imageinary2;

	cin >> real1 >> imaginary1;
	cin >> real2 >> imageinary2;

	complexNumber c1(real1, imaginary1);
	complexNumber c2(real2, imageinary2);

	int choice;
	cin >> choice;

	if (choice == 1) {
		c1.plus(c2);
		c1.print();
	}
	else if (choice == 2) {
		c1.multiply(c2);
		c1.print();
	}
	else {
		return 0;
	}
}