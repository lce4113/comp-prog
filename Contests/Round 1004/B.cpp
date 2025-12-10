// Codeforces Round 1004: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (auto x : a) mp[x]++;

    vector<int> gs(1, 1);
    while (gs.size()) {
        gs.clear();
        for (auto x : mp) {
            if (x.s > 2) {
                gs.push_back(x.f);
            }
        }
        for (auto x : gs) mp[x + 1]++, mp[x]--;
    }

    for (auto x : mp) {
        if (x.s % 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
