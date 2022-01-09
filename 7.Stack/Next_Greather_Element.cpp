#include<bits/stdc++.h>
using namespace std;

vector<int>nge(vector<int>arr){
	int n=arr.size();
	vector<int>ans(n);
	stack<int>s;
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && arr[i]<s.top()){
			s.pop();
		}
		if(s.empty()){
			ans[i]=-1;
		}
		else
			ans[i]=s.top();
		s.push(arr[i]);
	}
	return ans;
}

int main(){
vector<int>arr={2,3,1,7,6,4,5};
vector<int>ans=nge(arr);
for(int i=0;i<ans.size();i++){
	cout<<ans[i]<<" ";
}


return 0;
}