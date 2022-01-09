#include<bits/stdc++.h>
using namespace std;

string replace(string inp,char c1,char c2){
	//base case
	if(inp.length()==0){
		return "";
	}
	char ch;
	if(inp[0]==c1){
		ch=c2;
	}
	else{
		ch=inp[0];
	}
	string ans=replace(inp.substr(1),c1,c2);
	return ch+ans;

}

int main(){

	string str="abacd";
	char c1='a';
	char c2='x';
	cout<<replace(str,c1,c2);

	return 0;
}