// NAC 2025: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> c, pc(1, 0);

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos) {
        for (a[pos += n] = 1; pos /= 2;) {
            a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
    }
    int q(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += a[l++];
            if (r % 2) ans += a[--r];
        }
        return ans;
    }
};

vector<array<int, 3>> esl, esg;
vector<int> L, R;

void rec(int l, int r, int p) {
    if (r < l) return;
    // cout << l << ' ' << r << ' ' << p << '\n';
    if (L[p] != -1) rec(l, p - 1, L[p]);
    if (R[p] != -1) rec(p + 1, r, R[p]);
    // query -> {v, l, r}
    if (p - l < r - p) {
        for (int i = l; i <= p; i++) {
            esg.push_back({pc[i] + (k + 1) * max(c[p], 0ll) - 1, p + 1, r + 2});
        }
    } else {
        for (int i = p; i <= r; i++) {
            esl.push_back({pc[i + 1] - (k + 1) * max(c[p], 0ll), l, p + 1});
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    L.assign(n, -1), R.assign(n, -1);
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    c.assign(n, 0);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
        if (c[i] < 0) c[i] *= k;
    }
    stack<int> Q;
    for (int i = 0; i < n; i++) {
        while (Q.size() && c[Q.top()] < c[i]) Q.pop();
        if (Q.size() && (R[Q.top()] == -1 || c[i] > c[R[Q.top()]]))
            R[Q.top()] = i;
        Q.push(i);
    }
    while (Q.size()) Q.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (Q.size() && c[Q.top()] < c[i]) Q.pop();
        if (Q.size() && (L[Q.top()] == -1 || c[i] > c[L[Q.top()]]))
            L[Q.top()] = i;
        Q.push(i);
    }
    // for (auto x : L) cout << x << ' ';
    // cout << '\n';
    // for (auto x : R) cout << x << ' ';
    // cout << '\n';
    for (auto x : c) pc.push_back(pc.back() + x);
    // upd -> {v, -1, i}
    for (int i = 0; i < n + 1; i++) {
        esg.push_back({pc[i], -1, i});
        esl.push_back({pc[i], -1, i});
    }

    int p = max_element(c.begin(), c.end()) - c.begin();
    rec(0, n - 1, p);
    int ans = 0;
    sort(esl.begin(), esl.end());
    sort(esg.rbegin(), esg.rend());

    Tree seg(n + 1);
    for (auto [v, l, r] : esl) {
        if (l == -1) {
            seg.u(r);
        } else {
            ans += seg.q(l, r);
        }
    }
    Tree seg2(n + 1);
    for (auto [v, l, r] : esg) {
        if (l == -1) {
            seg2.u(r);
        } else {
            ans += seg2.q(l, r);
        }
    }
    cout << ans << '\n';
}