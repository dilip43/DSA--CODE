#include<iostream>

using namespace std;

void inc(int n){
	if(n==0){
		return;
	}
	inc(n-1);
	cout<<n<<endl;
}

int main(){
int n=5;
inc(n);

return 0;
}