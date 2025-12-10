// Codeforces Global Round 29: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int A = 0, B = 0;
    vector<int> os;
    for (auto [v, c] : mp) {
        if (v % 2) {
            A += c * (v / 2), B += c * (v / 2);
            os.push_back(c);
        } else {
            A += c * v / 2, B += c * v / 2;
        }
    }
    sort(os.rbegin(), os.rend());
    for (int i = 0; i < os.size(); i += 2) {
        A += os[i];
    }
    for (int i = 1; i < os.size(); i += 2) {
        B += os[i];
    }
    cout << A << ' ' << B << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}