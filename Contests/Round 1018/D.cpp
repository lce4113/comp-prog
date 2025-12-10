// Codeforces Round 1018: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f >> x.s;
    map<int, int> mp1, mp2;
    for (auto x : a) {
        mp1[x.f]++;
        mp2[x.s + x.f]++;
    }
    int X, Y;
    for (auto x : mp1) {
        if (x.s % 2) X = x.f;
    }
    for (auto x : mp2) {
        if (x.s % 2) Y = x.f - X;
    }
    cout << X << ' ' << Y << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
