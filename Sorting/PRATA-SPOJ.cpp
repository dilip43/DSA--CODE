#include <iostream>

using namespace std;

bool isPossible(int p, int cook[], int n, int mid) {

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        //for each cook count the pratas
        int c = 0;
        int time = mid;
        int perpratas = cook[i]; // time taken to cook each pratas by ith cook
        while (time > 0) {
            time = time - perpratas;
            if ( time >= 0) {
                c += 1;
                perpratas  += cook[i];
            }
        }
        cnt += c;
        if (cnt >= p)
            return true;
    }

    return false;
}

int minTime(int p, int cook[], int n) {
    int s = 0, e = 10000007;
    int mid, ans = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (isPossible(p, cook, n, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {

    //...............ignore this part
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("F:/input_output/input.txt", "r", stdin);
    freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here
    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        int n;
        cin >> n;
        int cook[n];
        for (int i = 0; i < n; i++)
            cin >> cook[i];

        cout << minTime(p, cook, n) << endl;
    }

    return 0;
}


