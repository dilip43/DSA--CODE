#include<bits/stdc++.h>
using namespace std;
int sum=0;

void printsubsetOfArrayHelper(int input[],int startindex,int size,int output[],int osize){
	if(startindex==size){
		for(int i=0;i<osize;i++){
       sum+=output[i];
		}
		return;
	}

		int smallOutput[40],smallOSize=0;
		printsubsetOfArrayHelper(input,startindex+1,size,output,osize);

		int i;
		for(i=0;i<osize;i++){
			smallOutput[i]=output[i];
		}
		smallOutput[i]=input[startindex];
		printsubsetOfArrayHelper(input,startindex+1,size,smallOutput,osize+1);
		
	}


void printsubsetOfArray(int input[],int size){
	int output[1000];
	return printsubsetOfArrayHelper(input,0,size,output,0);
}

int main(){
  int t,length;
  cin>>t;
  while(t--){
    cin>>length;
    int input[1000];
    
    	for(int i=0;i<length;i++)
		cin>>input[i];

	printsubsetOfArray(input,length);
    cout<<sum;
  }
	

return 0;
}