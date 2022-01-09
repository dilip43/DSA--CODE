#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin>>q;
    stack<int>s;
    while(q--){
    int type;
    cin>>type;
    if(type==1){
    int n;
    cin>>n;
    s.push(n);
}
else{
if(s.empty())
{
cout<<"kuchbhi"<<endl;
}
else
cout<<s.top()<<endl;
s.pop();

}
    return 0;
}
