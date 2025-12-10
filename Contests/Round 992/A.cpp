// Codeforces Round 992: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x % k]++;
    for (auto x : mp) {
        if (x.s == 1) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (a[i] % k == x.f) {
                    cout << i + 1 << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}