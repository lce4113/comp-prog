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

    void calc(int i) { seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }

    int get(int i) {
        assert(i >= 0), assert(i < N);
        return seg[i + n];
    }

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (auto &x : a) x--;

    vector<int> seg(n, 0);
    Seg tree = Seg(seg);
    vector<int> pairs(n);
    for (int i = 0; i < n; i++) {
        tree.u(a[i], tree.get(a[i]) + 1);
        pairs[i] = tree.q(a[i] + 1, n);
        // cout << a[i] << ' ' << pairs[i] << '\n';
    }

    vector<int> seg2(n, 0);
    Seg tree2 = Seg(seg2);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        tree2.u(a[i], tree2.get(a[i]) + pairs[i]);
        long long val = tree2.q(a[i] + 1, n);
        ans += val;
        // cout << a[i] << ' ' << pairs[i] << ' ' << val << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}