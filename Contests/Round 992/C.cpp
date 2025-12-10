// Codeforces Round 992: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    k--;

    vector<int> b;
    for (int i = 0; i < n - 1; i++) {
        b.push_back(k % 2);
        k /= 2;
    }
    if (k > 0) {
        cout << "-1\n";
        return;
    }
    reverse(b.begin(), b.end());
    b.push_back(0);

    // for (auto x : b) cout << x << ' ';
    // cout << '\n';

    vector<int> ans(n);
    int l = 0, r = n - 1;
    for (int i = 1; i <= n; i++) {
        if (b[i - 1]) {
            ans[r--] = i;
        } else {
            ans[l++] = i;
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}