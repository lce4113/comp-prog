// Codeforces Round 1007: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int sm = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int x = sqrt(sm + i);
        // cout << sm << ' ' << i << '\n';
        if (x * x == sm + i) {
            if (i + 1 > n) {
                cout << "-1\n";
                return;
            }
            ans.push_back(i + 1);
            ans.push_back(i);
            sm += i + 1 + i;
            i++;
        } else {
            ans.push_back(i);
            sm += i;
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // for (int i = 1; i <= 1000000; i++) {
    //     int x = i * (i + 1) / 2, y = sqrt(x);
    //     if (y * y == x) {
    //         cout << i << '\n';
    //     }
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}