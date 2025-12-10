// Codeforces Round 1039: Problem E

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int n, k;
int L, R;
vector<int> a;

bool check1(int m) {
    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + (x >= m) - (x < m));
    vector<int> mxi(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        if (pfs[i] > pfs[mxi[i + 1]])
            mxi[i] = i;
        else
            mxi[i] = mxi[i + 1];
    }
    for (int i = 0; i + k <= n; i++) {
        if (pfs[mxi[i + k]] >= pfs[i]) {
            L = i;
            R = mxi[i + k];
            return 1;
        }
    }
    return 0;
}

bool check2(int m) {
    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + (x <= m) - (x > m));
    vector<int> mxi(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        if (pfs[i] > pfs[mxi[i + 1]])
            mxi[i] = i;
        else
            mxi[i] = mxi[i + 1];
    }
    for (int i = 0; i + k <= n; i++) {
        if (pfs[mxi[i + k]] >= pfs[i]) {
            L = i;
            R = mxi[i + k];
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check1(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    int rv = l, L1 = L, R1 = R - 1;
    l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check2(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    vector<pair<int, int>> vals(rv + 1, {1e9, 1e9});
    int lv = r, L2 = L, R2 = R - 1;
    iset c;
    for (int i = L1; i <= R1; i++) c.insert({a[i], i});
    vector<array<int, 4>> rng;
    int med1 = c.find_by_order((c.size() - 1) / 2)->f;
    int med2 = c.find_by_order(c.size() / 2)->f;
    rng.push_back({med1, med2, L1, R1});
    while (L1 > L2) {
        L1--;
        c.insert({a[L1], L1});
        med1 = c.find_by_order((c.size() - 1) / 2)->f;
        med2 = c.find_by_order(c.size() / 2)->f;
        rng.push_back({med1, med2, L1, R1});
    }
    while (R1 < R2) {
        R1++;
        c.insert({a[R1], R1});
        med1 = c.find_by_order((c.size() - 1) / 2)->f;
        med2 = c.find_by_order(c.size() / 2)->f;
        rng.push_back({med1, med2, L1, R1});
    }
    while (L1 < L2) {
        c.erase({a[L1], L1});
        med1 = c.find_by_order((c.size() - 1) / 2)->f;
        med2 = c.find_by_order(c.size() / 2)->f;
        L1++;
        rng.push_back({med1, med2, L1, R1});
    }
    while (R1 > R2) {
        c.erase({a[R1], R1});
        med1 = c.find_by_order((c.size() - 1) / 2)->f;
        med2 = c.find_by_order(c.size() / 2)->f;
        R1--;
        rng.push_back({med1, med2, L1, R1});
    }
    sort(rng.begin(), rng.end());
    int chi = rng[0][1];
    for (int i = rng[0][0]; i <= rng[0][1]; i++) {
        vals[i] = {rng[0][2], rng[0][3]};
    }
    for (auto [lo, hi, lp, rp] : rng) {
        // cout << lo << ' ' << hi << ' ' << lp << ' ' << rp << '\n';
        for (int i = chi + 1; i <= hi; i++) {
            vals[i] = {lp, rp};
        }
        chi = max(chi, hi);
    }
    cout << rv - lv + 1 << '\n';
    for (int i = lv; i <= rv; i++) {
        cout << i << ' ' << vals[i].f + 1 << ' ' << vals[i].s + 1 << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}