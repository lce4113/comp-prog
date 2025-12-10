// CSES Sliding Window Problems: Sliding Window Advertisement

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), L(n), R(n);
    for (auto &x : a) cin >> x;
    stack<pair<int, int>> Q;
    Q.emplace(-1, 0);
    for (int i = 0; i < n; i++) {
        while (Q.top().f >= a[i]) Q.pop();
        L[i] = Q.top().s;
        Q.emplace(a[i], i + 1);
    }
    while (Q.size()) Q.pop();
    Q.emplace(-1, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        while (Q.top().f >= a[i]) Q.pop();
        R[i] = Q.top().s;
        Q.emplace(a[i], i - 1);
    }

    // for (auto x : L) cout << x << ' ';
    // cout << '\n';
    // for (auto x : R) cout << x << ' ';
    // cout << '\n';

    int W = n - k + 1;
    vector<pair<int, int>> inc(W), dec(W);
    vector<vector<int>> add(W), rem(W);
    for (int i = 0; i < n; i++) {
        if (R[i] - L[i] + 1 >= k) {
            int val = k * a[i];
            inc[L[i]] = max(inc[L[i]], {val, -a[i]});
            dec[L[i]] = {val, -a[i]};
        } else {
            int val = (R[i] - L[i] + 1) * a[i];
            if (L[i] < W) {
                inc[L[i]] = max(inc[L[i]], {val, -a[i]});
                add[L[i]].push_back(val);
            }
            if (R[i] - k + 1 >= 0) {
                dec[R[i] - k + 1] = max(dec[R[i] - k + 1], {val, -a[i]});
                rem[R[i] - k + 1].push_back(val);
            }
        }
    }
    for (auto x : dec) cout << x.f << ' ' << x.s << ", ";
    cout << '\n';
    for (auto x : inc) cout << x.f << ' ' << x.s << ", ";
    cout << '\n';
    for (int i = 1; i < W; i++) {
        pair<int, int> nval = {dec[i - 1].f + dec[i - 1].s, dec[i - 1].s};
        dec[i] = max(dec[i], nval);
    }
    for (int i = W - 2; i >= 0; i--) {
        pair<int, int> nval = {inc[i + 1].f + inc[i + 1].s, inc[i + 1].s};
        inc[i] = max(inc[i], nval);
    }
    // multiset<int> cur({0});
    // vector<int> rng(n);
    // for (int i = 0; i < n - k + 1; i++) {
    //     for (auto c : add[i]) cur.insert(c);
    //     for (auto c : rem[i]) cur.erase(cur.lower_bound(c));
    //     rng[i] = *cur.rbegin();
    // }

    // for (int i = 0; i < W; i++) {
    //     cout << max(max(inc[i].f, dec[i].f), rng[i]) << '\n';
    // }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}