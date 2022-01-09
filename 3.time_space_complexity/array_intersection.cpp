#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m) 
{
   sort(arr1,arr1+n);
   sort(arr2,arr2+m);

   
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
         int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] > nums2[j]) {
            j++;
        }
        else if (nums2[j] > nums1[i]) {
            i++;
        }
        else {
             
            // when both are equal
           ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
        return ans;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size1, size2;
		cin >> size1;
		int *input1 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];
		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}