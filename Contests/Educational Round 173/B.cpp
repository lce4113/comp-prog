// Codeforces Educational Round 173: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> ans(1, 1);
    if (n >= 3) {
        ans.push_back(3);
    } else if (d % 3 == 0) {
        ans.push_back(3);
    }
    if (d == 0 || d == 5) {
        ans.push_back(5);
    }
    if (n >= 3) {
        ans.push_back(7);
    } else if (d % 7 == 0) {
        ans.push_back(7);
    }
    if (n >= 6) {
        ans.push_back(9);
    } else if (d % 9 == 0) {
        ans.push_back(9);
    } else if (d % 3 == 0 && n >= 3) {
        ans.push_back(9);
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}