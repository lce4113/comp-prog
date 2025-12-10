// TOPC 2025: Problem I

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
using vi = vector<int>;

vector<int> p;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * n) {}
    void u(int pos) {
        for (a[pos += n]++; pos /= 2;) {
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

struct ONode {
    ONode *l = 0, *r = 0;
    int lo, hi, val = 0, cnt = 0, madd = 0;
    ONode(int _lo, int _hi) : lo(_lo), hi(_hi) {
        if (hi - lo == 1) return;
        int mid = (lo + hi) / 2;
        l = new ONode(lo, mid);
        r = new ONode(mid, hi);
    }
    void u(int pos) {
        if (pos < lo || pos >= hi) return;
        if (hi - lo == 1) {
            cnt = 1;
            return;
        }
        push();
        l->u(pos), r->u(pos);
        cnt = l->cnt + r->cnt;
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            val += x * cnt;
            madd += x;
        } else {
            l->add(L, R, x);
            r->add(L, R, x);
            val = l->val + r->val;
        }
    }
    void push() {
        if (hi - lo == 1) return;
        if (madd) {
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
    int q(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->q(L, R) + r->q(L, R);
    }
};

const int N = 2e5;
ONode ones(0, N);
Tree vents(N);

struct VNode {
    VNode *l = 0, *r = 0;
    int lo, hi, madd = 0, val;
    VNode(vi &v, int _lo, int _hi) : lo(_lo), hi(_hi) {
        if (hi - lo == 1) {
            val = v[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        l = new VNode(v, lo, mid);
        r = new VNode(v, mid, hi);
        val = min(l->val, r->val);
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val += x;
        } else {
            push();
            l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (madd) {
            if (l) l->add(lo, hi, madd);
            if (r) r->add(lo, hi, madd);
            madd = 0;
        }
    }
    void check() {
        if (val > 0) return;
        if (hi - lo == 1) {
            p[lo] /= 2;
            if (p[lo] == 1) {
                val = INF;
                ones.u(lo);
            } else {
                vents.u(lo);
                val = p[lo];
            }
            return;
        }
        push();
        l->check(), r->check();
        val = min(l->val, r->val);
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    p.assign(n, 0);
    for (auto &x : p) cin >> x;

    for (int i = 0; i < n; i++) {
        if (p[i] == 1) {
            p[i] = INF;
            ones.u(i);
        }
    }
    VNode vals(p, 0, n);

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            vals.add(l, r, -k);
            vals.check();
            ones.add(l, r, 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << vents.q(l, r) + ones.q(l, r) << '\n';
        }
    }
}