#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        a.push_back(y);
    }
    sort(a.begin(), a.end());
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    int l = 0, r = x + 1;
    while (r - l > 1) {
        // cout << 1 << '\n';
        int m = (l + r) / 2;
        set<int> ps;
        for (int i = 0; i <= a[0] - m; i++) {
            ps.insert(i);
            if (ps.size() >= k) goto done;
        }
        for (int i = a.back() + m; i <= x; i++) {
            ps.insert(i);
            if (ps.size() >= k) goto done;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int p = a[i] + m; p <= a[i + 1] - m; p++) {
                ps.insert(p);
                if (ps.size() >= k) goto done;
            }
        }
        // cout << m << ' ' << ps << '\n';
        r = m;
        continue;
    done:
        l = m;
    }
    set<int> ps;
    for (int i = 0; i <= a[0] - l; i++) {
        ps.insert(i);
        if (ps.size() >= k) goto out;
    }
    for (int i = a.back() + l; i <= x; i++) {
        ps.insert(i);
        if (ps.size() >= k) goto out;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int p = a[i] + l; p <= a[i + 1] - l; p++) {
            ps.insert(p);
            if (ps.size() >= k) goto out;
        }
    }
out:
    for (auto x : ps) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}