// MITIT Adv Round 1: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (auto &x : a) cin >> x.f >> x.s;
    for (auto &x : b) cin >> x.f >> x.s;

    vector<int> v0a, v0b, v1a, v1b;
    for (auto x : a) {
        if (x.s == 0) v0a.push_back(x.f);
        if (x.s == 1) v1a.push_back(x.f);
    }
    for (auto x : b) {
        if (x.s == 0) v0b.push_back(x.f);
        if (x.s == 1) v1b.push_back(x.f);
    }

    for (int i = 0, j = 0; i < (int)v0a.size() && j < (int)v0b.size(); i++) {
    }
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}