// CSES Range Queries: Polynomial Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    Node *l, *r;
    int lo, mid, hi, val;
    int madd = 0, mpol = 0;
    Node(vector<int> &v, int _lo, int _hi) : lo(_lo), hi(_hi) {
        if (lo + 1 == hi) {
            val = v[lo];
            return;
        }
        mid = lo + (hi - lo) / 2;
        l = new Node(v, lo, mid);
        r = new Node(v, mid, hi);
        val = l->val + r->val;
    }
    void u(int L, int R, int v) {
        if (R <= lo || L >= hi) return;
        if (L <= lo && hi <= R) {
            madd += v, mpol++;
            push();
            return;
        }
        l->u(L, R, v), l->push();
        r->u(L, R, v + mid - lo), r->push();
        val = l->val + r->val;
    }
    void push() {
        if (madd == 0 && mpol == 0) return;
        val += madd * (hi - lo);
        val += mpol * (hi - lo) * (hi - lo + 1) / 2;
        if (lo + 1 != hi) {
            l->madd += madd, l->mpol += mpol;
            r->madd += madd + mpol * (mid - lo), r->mpol += mpol;
        }
        madd = 0, mpol = 0;
    }
    int q(int L, int R) {
        if (R <= lo || L >= hi) return 0;
        if (L <= lo && hi <= R) return val;
        l->push(), r->push();
        return l->q(L, R) + r->q(L, R);
    }
    // void print() {
    //     cout << "lo-hi: " << lo << ' ' << hi << '\n';
    //     cout << "madd, mpol: " << madd << ' ' << mpol << '\n';
    //     cout << "val: " << val << '\n';
    //     if (l) l->print();
    //     if (r) r->print();
    // }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    Node *seg = new Node(a, 0, n);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if (t == 1) {
            seg->u(l, r, -l);
            // seg->print();
            // cout << '\n';
        } else {
            cout << seg->q(l, r) << '\n';
        }
    }
}