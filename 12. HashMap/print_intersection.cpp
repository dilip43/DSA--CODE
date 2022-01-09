#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void intersection(int arr1[], int arr2[]) {
	unorederd_map<int, int>map;
	for (int i = 0; i < arr1.size(); i++) {
		if (map.count(arr[i]) > 0) {
			map[arr[i]]++;
		}
		else
			map[arr[i]] = 1;
	}
	for (int i = 0; i < arr2.size(); i++) {
		if (map.count())
		}
}