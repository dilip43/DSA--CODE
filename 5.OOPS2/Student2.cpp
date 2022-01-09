class Student2{
public:
	int rollNumber;
	int age;

	static int totalStudents; //total number of students present

	Student2(){
		totalStudents++;
	}

	int getRollNumber(){
		return rollNumber;
	}

	static int getTotalStudent(){
		return totalStudents;
	}
};

int Student2 :: totalStudents=0; //initialize static data members