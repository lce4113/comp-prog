#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Seg {
    using F = int (*)(int, int);
    F comb = [](int a, int b) { return a + b; };
    int n, N;
    int ID = 0;
    vector<int> seg;

    Seg(vector<int> a) { init(a); }
    Seg(vector<int> a, int _ID) : ID(_ID) { init(a); }
    Seg(vector<int> a, F _comb) : comb(_comb) { init(a); }
    Seg(vector<int> a, F _comb, int _ID) : comb(_comb), ID(_ID) { init(a); }

    void init(vector<int> a) {
        N = a.size();
        n = binexp(2, ceil(log2(N)));
        seg.assign(n, 0);
        for (auto x : a) seg.push_back(x);
        for (int i = 0; i < n - N; i++) seg.push_back(0);
        for (int i = n - 1; i >= 0; i--) calc(i);
    }

    int binexp(int a, int b) {
        int ans = 1;
        for (; b; a *= a) {
            if (b % 2) ans *= a;
            b /= 2;
        }
        return ans;
    }

    int get(int i) { return seg[i + n]; }

    void calc(int i) { seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }

    void u(int i, int val) {
        assert(i >= 0), assert(i < N);
        i = i + n, seg[i] = val;
        for (i /= 2; i; i /= 2) calc(i);
    }

    int q(int L) { return q(L, L + 1); }
    int q(int L, int R) { return q(L, R, 0, n, 1); }
    int q(int L, int R, int l, int r, int i) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return ID;
        if (l >= L && r <= R) return seg[i];
        int ans = ID, m = (l + r) / 2;
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            b[0] = a[0];
            continue;
        }
        b[i] = a[i] - a[i - 1];
    }
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';
    Seg tree = Seg(b);
    while (q--) {
        int type;
        cin >> type;
        // cout << type << '\n';
        if (type == 2) {
            int k;
            cin >> k;
            // cout << k << '\n';
            int ans = tree.q(0, k);
            cout << ans << '\n';
        } else {
            int l, r, c;
            cin >> l >> r >> c;
            // cout << l << ' ' << r << ' ' << c << '\n';
            tree.u(l - 1, tree.get(l - 1) + c);
            if (r != n) tree.u(r, tree.get(r) - c);
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}