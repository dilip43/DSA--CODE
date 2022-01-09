#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool checkRedundantBracket(string input){
	stack<int>s;
	int i=0;
	while(i<input.length()){
		if(input[i]!=')'){
			s.push(input[i]);
		}
		else{
			int c=0;
			while(s.top()!='('){
				s.pop();
				++c;
			}
			s.pop();
			if(c==0)
				return true;
		}
		++i;
	}
	return false;
}

int main(){
string str="((a+b))";
bool ans=checkRedundantBracket(str);
if(ans==true)
	cout<<"1";
else
	cout<<"0";
return 0;
}