#include<bits/stdc++.h>
#include "Student.cpp"
using namespace std;

int main(){
	//create object statically
	Student s1;
	Student s2;
	Student s3,s4,s5;

	s1.rollNumber=101;
	
	cout<<s1.rollNumber<<endl;

	s1.display();

	//create object dynamically
	Student *s6=new Student;
	
	(*s6).rollNumber=104;
	
	(*s6).display();
	s6->display();

return 0;
}