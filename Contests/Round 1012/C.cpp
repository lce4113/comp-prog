// Codeforces Round 1012: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int N = sqrt(n * 2);
    for (auto &x : a) cin >> x;

    set<pair<int, pair<int, int>>> ht, ot;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            ht.insert({i * 3 + 1 + j * 3 + 1, {i * 3 + 1, j * 3 + 1}});
            ot.insert({i * 3 + 1 + j * 3 + 1, {i * 3 + 1, j * 3 + 1}});
            ot.insert({i * 3 + 2 + j * 3 + 1, {i * 3 + 2, j * 3 + 1}});
            ot.insert({i * 3 + 1 + j * 3 + 2, {i * 3 + 1, j * 3 + 2}});
            ot.insert({i * 3 + 2 + j * 3 + 2 + 2, {i * 3 + 2, j * 3 + 2}});
        }
    }

    vector<pair<int, int>> ans;
    for (auto x : a) {
        auto c = (x ? *ot.begin() : *ht.begin());
        ht.erase(c);
        ot.erase(c);
        ans.push_back(c.s);
    }

    for (auto x : ans) cout << x.f << ' ' << x.s << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}