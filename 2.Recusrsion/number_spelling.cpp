#include<iostream>
using namespace std;

char word[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void printspelling(int n){
	if(n==0)
	return;

	printspelling(n/10);
	int digit=n%10;
	cout<<word[digit]<<" ";
	return;
}


int main(){

	int n=2048;
	printspelling(n);

	return 0;
}