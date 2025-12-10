// Codeforces Round #988: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> ws(n);
    for (auto &x : ws) cin >> x.f >> x.s;
    vector<pair<int, int>> ps(m);
    for (auto &x : ps) cin >> x.f >> x.s;
    sort(ps.begin(), ps.end());
    priority_queue<int, vector<int>, less<int>> p;
    int c = 0, ans = 0, curr = 1;
    for (int i = 0; i < n; i++) {
        while (c < (int)ps.size() && ps[c].f < ws[i].f) p.push(ps[c++].s);
        int sz = ws[i].s - ws[i].f + 2;
        // cout << sz << ' ' << curr << '\n';
        // for (auto x : p) cout << x << ' ';
        // cout << '\n';
        while (curr < sz) {
            if (p.empty()) {
                cout << "-1\n";
                return;
            }
            // cout << p.top() << ' ';
            curr += p.top();
            p.pop();
            // cout << sz << ' ' << p[j] << '\n';
            ans++;
        }
        // cout << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}