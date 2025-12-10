// Codeforces Round 1008: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> m(n, {1, 1}), add(n, {0, 0});
    for (int i = 0; i < n; i++) {
        char o1, o2;
        int v1, v2;
        cin >> o1 >> v1 >> o2 >> v2;
        if (o1 == '+') add[i].f = v1;
        if (o2 == '+') add[i].s = v2;
        if (o1 == 'x') m[i].f = v1;
        if (o2 == 'x') m[i].s = v2;
    }

    vector<pair<int, int>> mdp(n + 1, {1, 1});
    for (int i = n - 1; i >= 0; i--) {
        mdp[i] = mdp[i + 1];
        mdp[i].f += (m[i].f - 1) * max(mdp[i + 1].f, mdp[i + 1].s);
        mdp[i].s += (m[i].s - 1) * max(mdp[i + 1].f, mdp[i + 1].s);
    }

    int ans = mdp[0].f + mdp[0].s;
    for (int i = 0; i < n; i++) {
        ans += add[i].f * max(mdp[i + 1].f, mdp[i + 1].s);
        ans += add[i].s * max(mdp[i + 1].f, mdp[i + 1].s);
    }

    // for (auto x : mdp) cout << x.f << ' ' << x.s << '\n';
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}