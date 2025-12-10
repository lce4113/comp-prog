// Codeforces Educational Round 173: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mxi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1 && a[i] != -1) mxi = i;
    }
    int sm = 0, l = a[mxi], r = a[mxi];
    for (int i = mxi; i < n; i++) {
        sm += a[i];
        l = min(sm, l);
        r = max(sm, r);
    }
    // cout << l << ' ' << r << '\n';
    int sml = l, smr = r;
    for (int i = mxi - 1; i >= 0; i--) {
        sml += a[i], smr += a[i];
        // cout << sml << ' ' << smr << '\n';
        l = min(sml, l);
        r = max(smr, r);
    }
    // cout << l << ' ' << r << '\n';

    int curr_sm = 0, mn_sm = 0, mx_sm = 0;
    int l1 = 0, r1 = 0;
    for (int i = 0; i < mxi; i++) {
        curr_sm += a[i];
        mn_sm = min(mn_sm, curr_sm);
        mx_sm = max(mx_sm, curr_sm);
        r1 = max(r1, curr_sm - mn_sm);
        l1 = min(l1, curr_sm - mx_sm);
    }

    curr_sm = 0, mn_sm = 0, mx_sm = 0;
    int l2 = 0, r2 = 0;
    for (int i = mxi + 1; i < n; i++) {
        curr_sm += a[i];
        mn_sm = min(mn_sm, curr_sm);
        mx_sm = max(mx_sm, curr_sm);
        // cout << mn_sm << ' ' << mx_sm << ' ' << curr_sm << '\n';
        r2 = max(r2, curr_sm - mn_sm);
        l2 = min(l2, curr_sm - mx_sm);
    }

    // cout << l << ' ' << r << '\n';
    // cout << l1 << ' ' << r1 << '\n';
    // cout << l2 << ' ' << r2 << '\n';
    // cout << '\n';

    set<int> ans;
    for (int i = l; i <= r; i++) ans.insert(i);
    for (int i = l1; i <= r1; i++) ans.insert(i);
    for (int i = l2; i <= r2; i++) ans.insert(i);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}