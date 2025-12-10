// Educational Codeforces Round 179: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(m);
    for (auto &x : a) cin >> x;
    map<string, vector<string>> mp;
    for (int i = 0; i < m; i++) {
        int sz = a[i].size();
        mp[a[i].substr(0, sz - 2)].push_back(a[i]);
    }

    // for (auto x : mp) {
    //     cout << x.f << ' ' << x.s.size() << '\n';
    // }

    priority_queue<pair<int, string>> Q;
    for (auto x : mp) {
        Q.push({x.s.size(), x.f});
        // cout << x.s.size() << ' ' << x.f << '\n';
    }

    map<string, int> mp2;
    for (int i = 0; i < n; i++) {
        auto x = Q.top();
        Q.pop();
        mp2[x.s]++;
        x.f--;
        Q.push(x);
    }

    vector<vector<string>> ans(n, vector<string>(6, ""));
    int c = 0;
    // cout << Q.size() << '\n';
    for (; c + 1 < n; c += 2) {
        auto x = Q.top();
        Q.pop();
        auto y = Q.top();
        Q.pop();
        // cout << x.f << ' ' << x.s << '\n';
        // cout << y.f << ' ' << y.s << '\n';
        if (y.f == 0) {
            Q.push(x), Q.push(y);
            break;
        }
        x.f--, y.f--;
        Q.push(x), Q.push(y);
        ans[c][0] = mp[x.s].back();
        ans[c + 1][0] = mp[y.s].back();
        mp[x.s].pop_back();
        mp[y.s].pop_back();
    }
    // if (Q.size()) cout << c << ' ' << Q.top().f << ' ' << Q.top().s << '\n';
    for (; c < n; c++) {
        auto x = Q.top();
        Q.pop();
        ans[c++][0] = mp[x.s].back();
        mp[x.s].pop_back();
        x.f--;
        Q.push(x);
    }

    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][i] = ans[j - j % 2 + (2 - j % 2)][i - 1];
        }
    }

    for (auto x : ans) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}