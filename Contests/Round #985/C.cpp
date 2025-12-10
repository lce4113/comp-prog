// Codeforces Round 985: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

bool check(vector<int> a, int x) {
    // cout << x << '\n';
    int n = a.size();
    vector<int> f(n + 1, 0);
    map<int, int> mp;
    mp[0] = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += (curr < a[i]) - (curr > a[i]);
        if (!mp.count(curr)) mp[curr] = i + 1;
    }
    // for (auto X : mp) cout << X.f << ' ' << X.s << '\n';
    curr = x;
    if (mp.count(curr) && mp[curr] < n) return true;
    for (int i = n - 1; i >= 0; i--) {
        curr += (a[i] < curr) - (a[i] >= curr);
        // cout << curr << ' ' << mp.count(curr) << '\n';
        if (mp.count(curr) && mp[curr] < i) return true;
        // cout << "hi\n";
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mx = INT_MIN;
    for (auto x : a) mx = max(mx, x);
    int l = 0, r = mx + 1, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if (check(a, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}