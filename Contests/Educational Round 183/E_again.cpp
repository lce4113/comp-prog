// Codeforces Educational Round 183: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Node {
    int lo, hi, mid, madd = 0, val;
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
    void add(int L, int R, int v) {
        if (L >= hi || R <= lo) return;
        if (L <= lo && hi <= R) {
            madd += v;
            val += v;
        } else {
            push();
            l->add(L, R, v);
            r->add(L, R, v);
            val = min(l->val, r->val);
        }
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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int ac, dr, n;
    cin >> ac >> dr >> n;
    vector<int> a(n), d(n);
    for (auto &x : a) cin >> x;
    for (auto &x : d) cin >> x;
    vector<int> c(n + 1);
    iota(c.rbegin(), c.rend(), -n);
    vector<int> p(n);
    Node tr(c, 0, n + 1);
    for (int i = 0; i < n; i++) {
        p[i] = max(0ll, a[i] - ac) + max(0ll, d[i] - dr);
        tr.add(p[i], n + 1, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int k, na, nd;
        cin >> k >> na >> nd;
        k--;
        tr.add(p[k], n + 1, -1);
        p[k] = max(0ll, na - ac) + max(0ll, nd - dr);
        tr.add(p[k], n + 1, 1);
        int ans = tr.walk();
        cout << (ans == -1 ? n : ans) << '\n';
    }
}