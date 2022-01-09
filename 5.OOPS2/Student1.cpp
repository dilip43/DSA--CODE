class Student1 {
public:
	int age;
	const int rollNumber;
	int &x; //age reference variable

	Student1(int r, int age): rollNumber(r), age(age), x(this.age) {
		// rollNumber = r;
	}

};