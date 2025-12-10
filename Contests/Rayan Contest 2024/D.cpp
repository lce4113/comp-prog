// Rayan Programming Contest 2024: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> s0, s1, s2;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) s0.insert(i);
        if (a[i] == 1) s1.insert(i);
        if (a[i] == 2) s2.insert(i);
    }
    int x, y;
    while (s2.size() && *s2.begin() != n - s2.size()) {
        if (s0.size() && *s1.rbegin() < n - s2.size()) {
            x = *s0.rbegin(), y = *s1.rbegin();
            ans.push_back({x, y});
            s0.erase(x), s1.erase(y);
            s0.insert(y), s1.insert(x);
        }
        x = *s2.begin(), y = *s1.rbegin();
        ans.push_back({x, y});
        s2.erase(x), s1.erase(y);
        s2.insert(y), s1.insert(x);
        // cout << x << ' ' << y << '\n';
    }
    while (s0.size() && *s0.rbegin() != s0.size() - 1) {
        x = *s0.rbegin(), y = *s1.begin();
        ans.push_back({x, y});
        s0.erase(x), s1.erase(y);
        s0.insert(y), s1.insert(x);
        // cout << x << ' ' << y << '\n';
    }

    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.f + 1 << ' ' << p.s + 1 << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}