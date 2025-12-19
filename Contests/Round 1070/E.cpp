// Codeforces Round 1070: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * n, -1e18) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int res = -1e18;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, a[l++]);
            if (r & 1) res = max(res, a[--r]);
        }
        return res;
    }
};

struct Node {
    int lo, hi, mid, mset = -1, val = 0, mx = 0;
    Node *L, *R;
    Node(int _lo, int _hi) : lo(_lo), hi(_hi) {
        mid = (lo + hi) / 2;
        if (hi - lo == 1) return;
        L = new Node(lo, mid);
        R = new Node(mid, hi);
    }
    void u(int l, int r, int v) {
        if (l <= lo && hi <= r) {
            mset = v;
            val = (hi - lo) * v;
            mx = v;
            return;
        }
        if (r <= lo || hi <= l) return;
        push();
        L->u(l, r, v), R->u(l, r, v);
        val = L->val + R->val;
        mx = max(L->mx, R->mx);
    }
    void push() {
        if (mset == -1) return;
        L->u(lo, hi, mset), R->u(lo, hi, mset);
        mset = -1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto &x : a) cin >> x[1];
    for (auto &x : a) cin >> x[0];
    for (int i = 0; i < n; i++) a[i][2] = i;
    vector<int> p(n);
    for (auto &x : p) cin >> x;

    vector<int> L(n), R(n);
    stack<pair<int, int>> Q;
    Q.push({1e18, -1});
    for (int i = 0; i < n; i++) {
        while (Q.top().f <= a[i][1]) Q.pop();
        L[i] = Q.top().s;
        Q.push({a[i][1], i});
    }
    while (Q.size()) Q.pop();
    Q.push({1e18, n});
    for (int i = n - 1; i >= 0; i--) {
        while (Q.top().f <= a[i][1]) Q.pop();
        R[i] = Q.top().s;
        Q.push({a[i][1], i});
    }

    sort(a.rbegin(), a.rend());
    Tree seg(n);
    Node tr(0, n);
    for (int i = 0; i < n; i++) {
        int l = 0, r = a[i][2];
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (seg.q(m, r) > a[i][1])
                l = m;
            else
                r = m;
        }
        int lo = seg.q(0, a[i][2]) <= a[i][1] ? -1 : l;
        l = a[i][2] + 1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (seg.q(l, m) > a[i][1])
                r = m;
            else
                l = m;
        }
        int hi = seg.q(a[i][2] + 1, n) <= a[i][1] ? n : l;
        seg.u(a[i][2], a[i][1]);
        tr.u(lo + 1, hi, a[i][0]);
    }
    cout << tr.val - tr.mx << ' ';
    for (int i = 0; i < n; i++) {
        tr.u(L[p[i] - 1] + 1, R[p[i] - 1], 0);
        cout << tr.val - tr.mx << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}