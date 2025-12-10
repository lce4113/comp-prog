// Codeforces Round 1012: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) c[i] = a[i] - b[i];

    // for (auto x : c) cout << x << ' ';
    // cout << '\n';

    int st = 0;
    bool val = false;
    for (int i = 0; i < n; i++) {
        if (c[i] > 0) {
            st = i;
            val = true;
            break;
        }
    }

    if (!val) {
        cout << 1 << '\n';
        return;
    }

    int mn = 0, nst = st;
    for (int i = (st - 1 + n) % n; i != st; i = (i - 1 + n) % n) {
        mn = min(mn + c[i], c[i]);
        // cout << i << ' ' << mn << '\n';
        if (mn > 0) nst = i;
    }
    // cout << nst << '\n';

    int ci = (nst + 1) % n, cs = c[nst], ans = 0;
    st = nst;
    for (; ci != st; ci = (ci + 1) % n) {
        cs += c[ci];
        if (cs <= 0) {
            ans = max(ans, (ci - nst + n) % n);
            nst = (ci + 1) % n, cs = 0;
        }
    }
    ans = max(ans, (ci - nst + n) % n);

    cout << ans + 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}