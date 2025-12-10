// CSES Additional Problems I: Bubble Sort Rounds II

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    multiset<pair<int, int>> rem;
    int c = 0;
    vector<int> ans(n, -1);
    for (auto [v, ps] : mp) {
        for (auto p : ps) {
            if (p - c < 0)
                rem.insert({p, v});
            else if (p - c <= k)
                ans[c] = v;
            else
                ans[p - k] = v;
            c++;
        }
    }
    auto it = rem.begin();
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) continue;
        ans[i] = it->second;
        it++;
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}