// Codeforces Round 990: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    if (n == 1) {
        cout << a << '\n';
        return;
    }
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    vector<pair<int, char>> ps;
    for (auto x : mp) ps.push_back({x.s, x.f});
    sort(ps.begin(), ps.end());
    for (auto &x : a) {
        if (x == ps[0].s) {
            x = ps.back().s;
            break;
        }
    }
    cout << a << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}