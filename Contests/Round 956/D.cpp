// Codeforces Round 956: Problem D

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
};

int inv(vector<int> a) {
    int n = a.size();
    vector<int> A = a;
    sort(a.begin(), a.end());
    map<int, int> pos;
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    vector<int> zs(n, 0);
    Seg sa = Seg(zs);
    int ans = 0;
    for (auto x : A) ans += sa.q(pos[x], n), sa.u(pos[x], 1);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    set<int> S;
    for (auto x : a) S.insert(x);
    for (auto x : b) {
        if (!S.count(x)) {
            cout << "NO\n";
            return;
        }
    }

    int inva = inv(a), invb = inv(b);

    if (inva % 2 != invb % 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}