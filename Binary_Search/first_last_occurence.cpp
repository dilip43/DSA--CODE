#include<bits/stdc++.h>
using namespace std;

int first_occurence(int arr[],int n,int key){
	int s=0;
	int e=n-1;

	int ans=-1;
	while(s<=e){
		int mid=(s+e)/2;

		if(arr[mid]==key){
			ans=mid;
			e=mid-1;
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans+1;
}


int last_occurence(int arr[],int n,int key){
	int s=0;
	int e=n-1;

	int ans=-1;
	while(s<=e){
		int mid=(s+e)/2;

		if(arr[mid]==key){
			ans=mid;
			s=mid+1;
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans+1;
}

int main(){
	int arr[]={1,2,5,8,8,8,8,10,12,15,20};
	int n=sizeof(arr)/sizeof(int);

	int key;
	cin>>key;

	cout<<first_occurence(arr,n,key)<<endl;
	cout<<last_occurence(arr,n,key);

	return 0;
}