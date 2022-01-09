#include <bits/stdc++.h>
using namespace std;
void findMaxNum(int arr[], int n) {
    int hash[10] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < hash[i]; j++)
            cout << i;
    }
}

int main() {

    //...............ignore this part
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("F:/input_output/input.txt", "r", stdin);
    freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here


    int arr[] = {3, 30, 34, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMaxNum(arr, n);
    return 0;
}
