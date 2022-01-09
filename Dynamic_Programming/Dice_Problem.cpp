#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[55][55];

int NoofWays(int face, int throws, int sum) {
	if (sum == 0 && throws == 0)
		return 1;

	if (sum < 0 || throws == 0)
		return 0;

	if (dp[throws][sum] != -1)
		return dp[throws][sum];

	int ans = 0;
	for (int i = 1; i <= face; i++) {
		ans += NoofWays(face, throws - 1, sum - i);
	}
	return dp[throws][sum] = ans;
}

int main(){
	int faces=6,throws=3,sum=12;
	cout<<NoofWays(faces,throws,sum)<<endl;
}