// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5

#include<bits/stdc++.h>
using namespace std;

int main() {

//...............ignore this part
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("F:/input_output/input.txt", "r", stdin);
    freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }


    return 0;
}