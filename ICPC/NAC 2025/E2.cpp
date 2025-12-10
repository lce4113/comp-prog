// NAC 2025: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int N = 2e5;
int n, k;
vector<int> c, pc(1, 0);

struct Tree1 {
    int n;
    vector<int> a;
    Tree1(int _n) : n(_n), a(2 * _n) {}
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

struct Tree2 {
    int n;
    vector<pair<int, int>> a;
    Tree2(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        for (a[pos + n] = {val, pos}, pos += n; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        pair<int, int> ans = {-1e18, -1e18};
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans = max(ans, a[l++]);
            if (r % 2) ans = max(ans, a[--r]);
        }
        return ans.s;
    }
};

vector<array<int, 3>> esl, esg;
vector<int> L, R;

Tree2 tr(N);

void rec(int l, int r) {
    if (r < l) return;
    // cout << l << ' ' << r << ' ' << p << '\n';
    int p = tr.q(l, r + 1);
    rec(l, p - 1), rec(p + 1, r);
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
    for (int i = 0; i < n; i++) {
        tr.u(i, c[i]);
    }
    for (auto x : c) pc.push_back(pc.back() + x);
    // upd -> {v, -1, i}
    for (int i = 0; i < n + 1; i++) {
        esg.push_back({pc[i], -1, i});
        esl.push_back({pc[i], -1, i});
    }

    rec(0, n - 1);
    int ans = 0;
    sort(esl.begin(), esl.end());
    sort(esg.rbegin(), esg.rend());

    Tree1 seg(n + 1);
    for (auto [v, l, r] : esl) {
        if (l == -1) {
            seg.u(r);
        } else {
            ans += seg.q(l, r);
        }
    }
    Tree1 seg2(n + 1);
    for (auto [v, l, r] : esg) {
        if (l == -1) {
            seg2.u(r);
        } else {
            ans += seg2.q(l, r);
        }
    }
    cout << ans << '\n';
}