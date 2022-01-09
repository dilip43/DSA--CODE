#include <bits/stdc++.h>
  using namespace std;
  
  void printbinary(int a[],int k,int n){
    //base case
    if(k==n){
      for(int i=0;i<n;i++){
        cout<<a[i];
      }
      cout<<endl;
       return;
    }
   if(a[k-1]==0){
     a[k]=0;
     printbinary(a,k+1,n);
     a[k]=1;
     printbinary(a,k+1,n);
   }
   else{
     a[k]=0;
     printbinary(a,k+1,n);
   }
  }
  
  int main()
  {
    int t;
    cin>>t;
    int n;
    while(t--){
      cin>>n;
      int arr[n];
      arr[0]=0;
      printbinary(arr,1,n);
      arr[0]=1;
      printbinary(arr,1,n);
    }
    
    return 0;
  }