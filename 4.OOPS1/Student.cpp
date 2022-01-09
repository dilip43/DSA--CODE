#include<iostream>
using namespace std;

class Student
{
public:
	int rollNumber;
private:
	int age;

public:
	void display(){
		cout<<age<<" "<<rollNumber;
	}

	int getAge(){
		return age;
	}

	void setAge(int a){
		age=a;
	}
};

