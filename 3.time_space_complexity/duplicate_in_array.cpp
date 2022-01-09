#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
bitset<3000001>bs;
for(int i:a){
	if(bs[a]!=0)
		return a;
	bs.set(a);
}
return 0;
}