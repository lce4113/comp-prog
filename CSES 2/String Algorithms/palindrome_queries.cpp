// CSES String Algorithms: Palindrome Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 2e5;
const int MOD = 1e9 + 7;
const int P = 53;
vector<int> pfs(1, 0), ps(MAXN + 1, 1);

struct Tree {
    using T = pair<int, int>;
    T f(T x, T y) { return {(x.f * ps[y.s] + y.f) % MOD, x.s + y.s}; }
    int n;
    vector<T> a;
    Tree(int _n) : n(_n) {
        n = 1 << (1 + __lg(_n));
        a.assign(2 * n, {0, 0});
    }
    void u(int pos, T val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        T ra = {0, 0}, rb = {0, 0};
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb).f;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) ps[i] = ps[i - 1] * P % MOD;

    int n, q;
    cin >> n >> q;

    string a;
    cin >> a;
    Tree seg(n), segr(n);
    for (int i = 0; i < n; i++)
        seg.u(i, {a[i] - 'a', 1}), segr.u(n - 1 - i, {a[i] - 'a', 1});

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int m1 = (l + r) / 2, m2 = (l + r) / 2;
            if ((r + l) % 2) m2++;
            cout << (seg.q(l, m1 + 1) == segr.q(n - r - 1, n - m2) ? "YES\n"
                                                                   : "NO\n");
        } else {
            int k;
            char v;
            cin >> k >> v;
            k--;
            seg.u(k, {v - 'a', 1});
            segr.u(n - 1 - k, {v - 'a', 1});
        }
    }
}