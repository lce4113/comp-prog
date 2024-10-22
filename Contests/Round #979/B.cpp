#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    set<pair<int, int>> a;
    cout << 1;
    for (int i = 1; i < n; i++) {
        cout << "0";
    }
    cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     int x = i * (i + 1) / 2;
    //     a.insert({x, i});
    // }
    // int goal = (n * (n + 1) / 2);
    // auto zeros = *(--a.lower_bound({goal, n + 1}));
    // cout << goal << ' ' << zeros.first << ' ' << zeros.second << '\n';
    // goal -= x.first;
    // zeros.push_back(x.second);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}