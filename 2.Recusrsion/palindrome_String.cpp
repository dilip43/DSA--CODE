#include <bits/stdc++.h>
  using namespace std;
  
 int checkpalindrome(char input[],int start,int end){
 	if(input[0]=='\0' || input[1]=='\0'){
 		return 1;
 	}
 	if(start>=end){
 		return 1;
 	}
 	if(input[start]==input[end]){
 		return checkpalindrome(input,start+1,end-1);
 	}
 	else{
 		return 0;
 	}
 }

 int main(){
 	char input[50];
 	cin>>input;
 	int len=strlen(input);
 	int ans=checkpalindrome(input,0,len-1);
 	if(ans){
 		cout<<"true";
 	}
 	else{
 		cout<<"false";
 	}
 	return 0;
 }
 