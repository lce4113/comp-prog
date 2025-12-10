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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> pfs(n + 1, 0);
    for (int i = 0; i < n; i++) pfs[i + 1] = pfs[i] + a[i];
    vector<int> dp(n + 1, -1);
    vector<int> a(n + 1, 0);
    Seg cnt = Seg(a);
    dp[0] = 0;
    cnt.u(0, 1), cnt.u(1, -1);
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) continue;
            auto it = upper_bound(pfs.begin(), pfs.end(), pfs[i] + b[k]);
            int ind = it - pfs.begin();
            ind--;
            int next = dp[i] + (m - 1 - k);
            if (dp[ind] == -1 || next < dp[ind]) {
                dp[ind] = next;
                cnt.u(ind, cnt.get(ind) + 1), cnt.u(ind + 1, cnt.get(ind) - 1);
            } else if (next == dp[ind]) {
                cnt.u(ind, cnt.q(0, ind));
            }
        }
        // for (auto x : dp) cout << x << ' ';
        // cout << '\n';
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}