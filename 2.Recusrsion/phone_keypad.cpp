#include<bits/stdc++.h>
using namespace std;

char keyboard[][]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generate_names(char *in,char *out,int i,int j){
	//base case
	if(in[i]=='\0'){
		out[j]=in[i];
		cout<<out<<endl;
		return
	}
	//rec case
	int digit=in[i]-'0';
	if(digit==1 || digit==0){
		generate_names(in,out,i+1,j);
	}
for(int k=0;keypad[digit][k]!='\0';k++){
	out[j]=keypad[digit][k];
	generate_names(in,out,i+1,j+1);
}

}

int main(){
char in[100];
cin>>n;
char out[100];

generate_names(in,out,0,0);
return 0;


return 0;
}