// Codeforces Round 1002: Problem E
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

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
        n = 1 << (int)ceil(log2(N));
        seg.assign(n, ID);
        for (auto x : a) seg.push_back(x);
        for (int i = 0; i < n - N; i++) seg.push_back(ID);
        for (int i = n - 1; i >= 1; i--) calc(i);
    }

    void calc(int i) { seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }

    int get(int i) {
        assert(i >= 0), assert(i < N);
        return seg[i + n];
    }

    void u(int i, int val) {
        // assert(i >= 0), assert(i < N);
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

    int qv(int v) { return qv(0, n, 1, v); }
    int qv(int l, int r, int i, int v) {
        // assert(v >= 1), assert(v <= seg[1]);
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        if (seg[2 * i + 1] < v) return qv(l, m, 2 * i, v - seg[2 * i + 1]);
        return qv(m, r, 2 * i + 1, v);
    }
};

int n, m;
vector<vector<int>> a, b;
vector<vector<pair<int, int>>> ans, esc;

void out() {
    // for (auto x : ans) {
    //     for (auto y : x) cout << y.f << ' ' << y.s << '\n';
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<vector<pair<int, int>>> nans;
    nans.assign(n, {});
    int N = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = 0; k < m; k++) {
            if (j < (int)ans[i].size() && ans[i][j].f == k) {
                j++;
            } else {
                nans[i].push_back({k, b[i][k]});
            }
        }
        N += nans[i].size();
    }
    ans = nans;

    // for (auto x : nans) {
    //     for (auto y : x) cout << y.f << ' ' << y.s << '\n';
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<pair<int, int>> sorted(N);
    Seg seg(vector<int>(N, 1));
    for (int i = n - 1; i >= 0; i--) {
        vector<int> ps;
        for (auto x : ans[i]) {
            int p = seg.qv(x.f + 1);
            sorted[p] = {i + 1, x.s};
            ps.push_back(p);
        }
        for (auto x : ps) seg.u(x, 0);
    }

    cout << N << '\n';
    for (auto x : sorted) cout << x.f << ' ' << x.s << '\n';
}

void solve() {
    cin >> n >> m;
    a.assign(n, vector<int>(m)), b.assign(n, vector<int>(m));
    vector<pair<int, int>> al, bl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            al.push_back({a[i][j], i});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            bl.push_back({b[i][j], i});
        }
    }

    ans.assign(n, {});
    esc = ans;
    for (int i = 0, j = 0; j < n * m; j++) {
        // cout << al[i].s << ' ' << al[i - 1].s << '\n';
        if (al[i].f == bl[j].f) {
            if (j + 1 < n * m && al[i].s == bl[j].s &&
                al[i + 1].s == bl[j + 1].s && al[i].s == al[i + 1].s &&
                al[i + 1].f != bl[j + 1].f) {
                ans = esc;
                out();
                return;
            }
            i++;
            ans[bl[j].s].push_back({j - bl[j].s * m, bl[j].f});
            if (i < n * m && al[i].s != al[i - 1].s) esc = ans;
        }
    }

    out();
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // Seg seg(vector<int>(6, 1));
    // seg.u(2, 0);
    // seg.u(4, 0);
    // seg.u(5, 0);
    // 110100
    // cout << seg.qv(2) << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}