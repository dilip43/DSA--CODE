#include<iostream>
using namespace std;

bool isSorted(int a[],int n){
if(n==0 || n==1){
	return true;
}

if(a[0]<a[1] && isSorted(a+1,n-1)){
	return true;
}
return false;

}

int main(){
int arr[]={1,2,3,4};
int size=sizeof(arr)/sizeof(int);
cout<<isSorted(arr,size);


return 0;
}