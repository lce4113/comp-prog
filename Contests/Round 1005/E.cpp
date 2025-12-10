// Codeforces Round 1005
// Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;
const int MAXN = 2e5 + 10;
vector<int> fact(MAXN + 1, 1), fact_inv(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

struct DSU {
    vector<int> ps, sz;
    DSU(int n) : ps(n), sz(n, 1) {
        for (int i = 0; i < n; i++) ps[i] = i;
    }

    int f(int x) { return ps[x] == x ? x : (ps[x] = f(ps[x])); }
    bool sm(int x, int y) { return f(x) == f(y); }

    void u(int x, int y) {
        int xr = f(x), yr = f(y);
        if (xr == yr) return;
        if (sz[xr] < sz[yr]) swap(xr, yr);
        sz[xr] += sz[yr];
        ps[yr] = xr;
    }

    map<int, int> cs() {
        map<int, int> rs;
        for (int i = 0; i < (int)ps.size(); i++) rs[f(i)]++;
        return rs;
    }
};

struct Seg {
    using F = int (*)(int, int);
    F comb = [](int a, int b) { return max(a, b); };
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
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[b[i]].push_back(i);

    Seg seg(a);
    DSU d(n);
    for (auto x : mp) {
        for (int i = 0; i < (int)x.s.size() - 1; i++) {
            // cout << x.s[i] << ' ' << x.s[i + 1] << '\n';
            // cout << seg.q(x.s[i] + 1, x.s[i + 1]) << '\n';
            if (seg.q(x.s[i] + 1, x.s[i + 1]) <=
                min(a[x.s[i]], a[x.s[i + 1]])) {
                d.u(x.s[i], x.s[i + 1]);
                // if (a[x.s[i]] == a[x.s[i + 1]]) sm[x.f]++;
            }
        }
    }

    map<pair<int, int>, int> nums;
    for (int i = 0; i < n; i++) nums[{d.f(i), a[i]}]++;
    for (int i = 0; i < n; i++) cout << setw(2) << b[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << setw(2) << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << setw(2) << d.f(i) << ' ';
    cout << '\n';

    int ans = 1;
    for (auto x : d.cs()) ans *= fact[x.s], ans %= MOD;
    for (auto x : nums) ans *= fact_inv[x.s], ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i, fact[i] %= MOD;
    for (int i = 1; i <= MAXN; i++) fact_inv[i] = binexp(fact[i]);

    int t = 1;
    cin >> t;
    while (t--) solve();
}