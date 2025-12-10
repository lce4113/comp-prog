// CSES Range Queries: Range Updates and Sums

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Seg {
    using F = int (*)(int, int);
    F comb = [](int a, int b) { return a + b; };
    int n, N;
    int ID = 0;
    vector<int> seg;
    vector<pair<int, int>> lazy;

    Seg(vector<int> a) { init(a); }
    Seg(vector<int> a, int _ID) : ID(_ID) { init(a); }
    Seg(vector<int> a, F _comb) : comb(_comb) { init(a); }
    Seg(vector<int> a, F _comb, int _ID) : comb(_comb), ID(_ID) { init(a); }

    void init(vector<int> a) {
        N = a.size();
        n = 1 << (int)ceil(log2(N));
        seg.assign(n, ID);
        for (auto x : a) seg.push_back(x);
        while ((int)seg.size() < 2 * n) seg.push_back(ID);
        for (int i = n - 1; i >= 0; i--) calc(i);
        lazy.assign(2 * n, {0, 0});
    }

    int get(int i) {
        assert(i >= 0), assert(i < N);
        return seg[i + n];
    }

    void prop(int i, int len) {
        if (lazy[i].s) {
            seg[i] = lazy[i].f * len;
        } else {
            seg[i] += lazy[i].f * len;
        }
        if (len == 1) {
            lazy[i] = {0, 0};
            return;
        }
        if (lazy[i].s) {
            lazy[2 * i] = lazy[2 * i + 1] = lazy[i];
        } else {
            lazy[2 * i].f += lazy[i].f;
            lazy[2 * i + 1].f += lazy[i].f;
        }
        lazy[i] = {0, 0};
    }
    void calc(int i) { seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }

    void setr(int L, int R, int v) { return setr(L, R, 0, n, 1, v); }
    void setr(int L, int R, int l, int r, int i, int v) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return;
        if (l >= L && r <= R) {
            lazy[i] = {v, 1};
            prop(i, r - l);
            return;
        }
        // lazy prop
        int m = (l + r) / 2;
        prop(2 * i, m - l);
        prop(2 * i + 1, r - m);
        setr(L, R, l, m, 2 * i, v);
        setr(L, R, m, r, 2 * i + 1, v);
        // pull
        calc(i);
    }

    void ur(int L, int R, int v) { return ur(L, R, 0, n, 1, v); }
    void ur(int L, int R, int l, int r, int i, int v) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return;
        if (l >= L && r <= R) {
            lazy[i].f += v;
            prop(i, r - l);
            return;
        }
        // lazy prop
        int m = (l + r) / 2;
        prop(2 * i, m - l);
        prop(2 * i + 1, r - m);
        ur(L, R, l, m, 2 * i, v);
        ur(L, R, m, r, 2 * i + 1, v);
        // pull
        calc(i);
    }

    int q(int L, int R) { return q(L, R, 0, n, 1); }
    int q(int L, int R, int l, int r, int i) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return ID;
        if (l >= L && r <= R) return seg[i];
        int ans = ID, m = (l + r) / 2;
        // lazy prop
        prop(2 * i, m - l);
        prop(2 * i + 1, r - m);
        ans = comb(ans, q(L, R, l, m, 2 * i));
        ans = comb(ans, q(L, R, m, r, 2 * i + 1));
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    Seg seg = Seg(a);
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.ur(l, r, x);
        } else if (typ == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.setr(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            // for (auto x : seg.seg) cout << x << ' ';
            // cout << '\n';
            // for (auto x : seg.lazy) cout << x.f << ' ' << x.s << ", ";
            // cout << '\n';
            cout << seg.q(l, r) << '\n';
            // for (auto x : seg.seg) cout << x << ' ';
            // cout << '\n';
            // for (auto x : seg.lazy) cout << x.f << ' ' << x.s << ", ";
            // cout << '\n';
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}