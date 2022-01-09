#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(int nums[],int n,int sumTareget){
	vector<vector<int>>res;
	if(n<=2)
		return res;

	sort(nums,nums+n);

for(int i=0;i<n;i++){

	if(i>0 && nums[i]==nums[i-1]) //avoid duplicate triplets count
		continue;

	int num=nums[i];
int target=sumTareget-num;
	for(int l=i+1;r=n-1;l<r;){
		if(nums[l]+nums[r]>target)
			r--;
		else if(nums[l]+nums[r]<target)
			l++;
		else{
			res.push_back({nums[i],nums[l],nums[r]});

			//skip duplicats
			while(l<n-1 && nums[l]==nums[l+1]) l++;
			while(r>0 && numr[r]==nums[r-1]) r--;

			l++;
			r--;
		}
	}

}
 return res;
	
}

int main(){
int arr[]={0,-1,2,-3,1};
int n=sizeof(arr)/sizeof(int);
int sum=-2;
vector<vector<int>>res=findTriplets(arr,n,sum);
cout<<"Unique triplets found are :\n";
for(int i=0;i<res.size();i++)
cout<<res[i][0]<<" "res[i][1]<<" "res[i][2]<<"\n";

return 0;
}