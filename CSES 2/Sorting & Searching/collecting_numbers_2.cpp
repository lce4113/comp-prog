// CSES Sorting & Searching: Collecting Numbers II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), p(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) p[--a[i]] = i;

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans += p[i] > p[i + 1];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        set<int> ps({a[x], a[x] - 1, a[y], a[y] - 1});
        for (auto c : ps) {
            if (c + 1 == n) continue;
            ans -= p[c] > p[c + 1];
        }
        swap(p[a[x]], p[a[y]]);
        swap(a[x], a[y]);
        for (auto c : ps) {
            if (c + 1 == n) continue;
            ans += p[c] > p[c + 1];
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}