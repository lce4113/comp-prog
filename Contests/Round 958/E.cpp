// Codeforces Round 958: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
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
        seg.assign(n, 0);
        for (auto x : a) seg.push_back(x);
        for (int i = 0; i < n - N; i++) seg.push_back(0);
        for (int i = n - 1; i >= 0; i--) calc(i);
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

    int qr(int L, int R, int v) { return qr(L, R, v, 0, n, 1); }
    int qr(int L, int R, int v, int l, int r, int i) {
        // cout << L << ' ' << R << ' ' << v << ' ' << l << ' ' << r << ' ' << i
        //      << ' ' << seg[i] << '\n';
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return N;
        if (seg[i] > v) return N;
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        if (l >= L && r <= R) {
            if (seg[i * 2] <= v) return qr(L, R, v, l, m, i * 2);
            return qr(L, R, v, m, r, i * 2 + 1);
        }
        int lv = qr(L, R, v, l, m, i * 2);
        if (lv != N) return lv;
        return qr(L, R, v, m, r, i * 2 + 1);
    }

    int ql(int L, int R, int v) { return ql(L, R, v, 0, n, 1); }
    int ql(int L, int R, int v, int l, int r, int i) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return -1;
        if (seg[i] > v) return -1;
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        if (l >= L && r <= R) {
            if (seg[i * 2 + 1] <= v) return ql(L, R, v, m, r, i * 2 + 1);
            return ql(L, R, v, l, m, i * 2);
        }
        int rv = ql(L, R, v, m, r, i * 2 + 1);
        if (rv != -1) return rv;
        return ql(L, R, v, l, m, i * 2);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    Seg mn = Seg(a, [](int x, int y) { return min(x, y); }, 1e9);

    vector<int> nl(n), nr(n);
    for (int i = 0; i < n; i++) nr[i] = mn.qr(i + 1, n, a[i]);
    for (int i = 0; i < n; i++) nl[i] = mn.ql(0, i, a[i]);

    // cout << "one:\n";
    // for (auto x : nl) cout << x << ' ';
    // cout << '\n';
    // for (auto x : nr) cout << x << ' ';
    // cout << '\n';

    vector<int> nl2(n), nr2(n);
    for (int i = 0; i < n; i++) {
        if (nr[i] == n) {
            nr2[i] = n;
            continue;
        }
        mn.u(nr[i], 1e9);
        nr2[i] = mn.qr(i + 1, n, a[i]);
        mn.u(nr[i], a[nr[i]]);
    }
    for (int i = 0; i < n; i++) {
        if (nl[i] == -1) {
            nl2[i] = -1;
            continue;
        }
        mn.u(nl[i], 1e9);
        nl2[i] = mn.ql(0, i, a[i]);
        mn.u(nl[i], a[nl[i]]);
    }

    // cout << "two:\n";
    // for (auto x : nl2) cout << x << ' ';
    // cout << '\n';
    // for (auto x : nr2) cout << x << ' ';
    // cout << '\n';

    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int rs = (nr[i] - i) * (i - nl[i]);
        ans[0] += a[i] * rs;
        // cout << a[i] * rs << '\n';
        ans[i] -= a[i] * rs;
        ans[i + 1] += a[i] * rs;
    }

    // for (auto x : ans) cout << x << ' ';
    // cout << '\n';

    for (int i = 0; i < n; i++) {
        if (nl[i] != -1) {
            ans[nl[i]] += a[i] * (nr[i] - i) * (nl[i] - nl2[i] - 1);
            ans[nl[i] + 1] -= a[i] * (nr[i] - i) * (nl[i] - nl2[i] - 1);
        }
        ans[nl[i] + 1] += a[i] * (nr[i] - i) * (-1);
        ans[i] -= a[i] * (nr[i] - i) * (-1);
        ans[i + 1] += a[i] * (-1) * (i - nl[i]);
        ans[nr[i]] -= a[i] * (-1) * (i - nl[i]);
        if (nr[i] != n) {
            ans[nr[i]] += a[i] * (nr2[i] - nr[i] - 1) * (i - nl[i]);
            ans[nr[i] + 1] -= a[i] * (nr2[i] - nr[i] - 1) * (i - nl[i]);
        }
    }

    // for (auto x : ans) cout << x << ' ';
    // cout << '\n';

    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += ans[i];
        cout << curr << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}