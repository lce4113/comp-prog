// MITIT Adv Round 2: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }

    set<int> ps;
    for (auto x : a) ps.insert(x);

    vector<vector<int>> cls;
    while (ps.size()) {
        int st = *ps.begin(), curr = a[st];
        vector<int> cl;
        ps.erase(st), cl.push_back(st);
        ps.erase(curr), cl.push_back(curr);
        // cout << curr << ' ' << st << '\n';
        bool add = true;
        while (curr != st) {
            // cout << curr << '\n';
            curr = a[curr];
            cl.push_back(curr);
            if (!ps.count(curr)) {
                add = false;
                break;
            }
            ps.erase(curr);
        }
        if (add) cls.push_back(cl);
    }
    // for (auto x : cls) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) adj[a[i]].push_back(i);

    vector<vector<int>> ans;
    vector<bool> vis(n, false);
    queue<int> Q;
    for (auto cl : cls) {
        Q.push(cl[0]);
        vis[cl[0]] = true;
    }
    while (Q.size()) {
        int c = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (vis[x]) continue;
            Q.push(x);
            if (a[c] != a[x]) {
                ans.push_back({1, c + 1, x + 1});
                swap(a[c], a[x]);
            }
            vis[x] = true;
        }
    }

    for (auto cl : cls) {
        // cout << cl.size() << '\n';
        for (int i = (int)cl.size() - 2; i >= 1; i--) {
            swap(a[cl[i]], a[cl[i - 1]]);
            // cout << "1 " << cl[i] + 1 << ' ' << cl[i - 1] + 1 << '\n';
            ans.push_back({1, cl[i] + 1, cl[i - 1] + 1});
        }
    }
    for (auto x : a) cout << x << ' ';
    cout << '\n';

    for (int i = 0; i < n; i++) {
        if (a[i] != i) ans.push_back({2, i + 1, a[i] + 1});
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}