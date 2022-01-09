#include <bits/stdc++.h>
  using namespace std;
  
  void print(int arr[],int n,int k){
    //base case
    if(n==k){
      for(int i=0;i<n;i++){
        cout<<arr[i];
      }
      cout<<endl;
    }

    //rec.case
    for(int i=1;i<=9;i++){
      arr[k]=i;
      print(arr,n,k++);
    }
  }
  
  int main()
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<9;i++){
      arr[i]=i+1;
      print(arr,n,1);
    }  
    return 0;
  }