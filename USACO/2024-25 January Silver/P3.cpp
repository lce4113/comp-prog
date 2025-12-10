// USACO 2024-25 January Silver
// Problem 3. "Table Recovery"

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void out(vector<vector<int>> ans) {
    int n = ans.size();
    for (auto x : ans) {
        // for (auto y : x) cout << y << ' ';
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << ' ';
            cout << x[i];
        }
        cout << '\n';
    }
    // cout << '\n';
}

bool cmp(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < b[i][j]) return true;
            if (a[i][j] > b[i][j]) return false;
        }
    }
    return false;
}

map<int, int> follow(vector<vector<pair<int, int>>> b, int rf, int rl) {
    int n = b.size();
    map<int, int> ans;

    for (int i = 0; i < n; i++) ans[b[rf][i].s] = i + 2;
    for (int i = 0; i < n; i++) ans[b[rl][i].s] = 2 * n - i;

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), ans1, ans2;
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }

    if (n == 1) {
        cout << a[0][0] << '\n';
        // cout << '\n';
        return;
    }

    map<int, int> mp;
    for (auto x : a) {
        for (auto y : x) mp[y]++;
    }

    vector<vector<pair<int, int>>> b;
    map<int, int> rmp;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> x2;
        for (auto y : a[i]) x2.push_back({mp[y], y});
        sort(x2.begin(), x2.end());
        b.push_back(x2);
        rmp[x2[0].s] = i;
    }

    vector<int> os;
    for (auto x : mp) {
        if (x.s == 1) os.push_back(x.f);
    }

    auto mp1 = follow(b, rmp[os[0]], rmp[os[1]]);
    auto mp2 = follow(b, rmp[os[1]], rmp[os[0]]);

    ans1 = ans2 = a;
    for (auto &x : ans1)
        for (auto &y : x) y = mp1[y];
    for (auto &x : ans2)
        for (auto &y : x) y = mp2[y];

    if (cmp(ans1, ans2)) {
        out(ans1);
    } else {
        out(ans2);
    }
    // cout << '\n';
    // out(ans1);
    // cout << '\n';
    // out(ans2);
    // cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
