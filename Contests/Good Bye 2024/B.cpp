// Codeforces Good Bye 2024 Round: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

pair<int, int> inter(pair<int, int> a, pair<int, int> b) {
    if (a.f > b.f) swap(a, b);
    if (b.f > a.s) return {-1, -1};
    return {max(a.f, b.f), min(a.s, b.s)};
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f >> x.s;

    string ans = "";
    for (auto x : a) ans += '1';

    multiset<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i].f == a[i].s) pos.insert(a[i].f);
    }

    // for (auto x : pos) cout << x << ' ';
    // cout << '\n';

    vector<int> ppfs(1, 0);
    for (int i = 0; i < 2 * n + 5; i++) {
        ppfs.push_back(ppfs.back() + (pos.count(i) > 0));
    }

    // for (auto x : ppfs) cout << x << ' ';
    // cout << '\n';

    for (int i = 0; i < n; i++) {
        int val = ppfs[a[i].s + 1] - ppfs[a[i].f];
        if (pos.count(a[i].f) == 1 && a[i].f == a[i].s) val--;
        if (val >= a[i].s - a[i].f + 1) ans[i] = '0';
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}