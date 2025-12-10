// MITIT Spring Invitational Qualification Round 2
// P1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = {b[i] - a[i], a[i]};
    }
    sort(c.begin(), c.end());

    int sm = 0;
    for (int i = 0; i < n; i++) {
        if (sm >= c[i].f)
            sm += c[i].s;
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}