// Codeforces Educational Round 183: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Node {
    int lo, hi, mid, val, madd = 0;
    Node *l, *r;
    Node(vector<int> &v, int _lo, int _hi) : lo(_lo), hi(_hi) {
        mid = (lo + hi) / 2;
        if (hi - lo == 1) {
            val = v[lo];
            return;
        }
        l = new Node(v, lo, mid), r = new Node(v, mid, hi);
        val = min(l->val, r->val);
    }
    void add(int L, int R, int x) {
        if (L >= hi || R <= lo) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val += x;
        } else {
            push();
            l->add(L, R, x);
            r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void pr() {
        if (hi - lo == 1) {
            cout << lo << ' ' << hi << ' ' << val << '\n';
            return;
        }
        push();
        l->pr();
        r->pr();
    }
    void push() {
        if (madd && hi - lo != 1) {
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
    int walk() {
        if (val > 0) return -1;
        if (hi - lo == 1) return lo;
        push();
        if (l->val <= 0) return l->walk();
        return r->walk();
    }
};

void solve() {
    int ac, dr, n;
    cin >> ac >> dr >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> d(n);
    for (auto &x : d) cin >> x;
    vector<int> c(n + 1);
    iota(c.rbegin(), c.rend(), -n);
    Node tr(c, 0, n + 1);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = max(a[i] - ac, 0ll) + max(d[i] - dr, 0ll);
        tr.add(p[i], n + 1, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int i, na, nd;
        cin >> i >> na >> nd;
        i--;
        tr.add(p[i], n + 1, -1);
        // tr.pr();
        // cout << '\n';
        p[i] = max(na - ac, 0ll) + max(nd - dr, 0ll);
        tr.add(p[i], n + 1, 1);
        int ans = tr.walk();
        // tr.pr();
        // cout << '\n';
        cout << (ans == -1 ? n : ans) << '\n';
        // cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}