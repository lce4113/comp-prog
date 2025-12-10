// Codeforces Round 1012: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Seg {
    using F = int (*)(int, int);
    F comb = [](int a, int b) { return min(a, b); };
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

int mni = 0;

bool ch(vector<int> a, vector<int> pc, int m) {
    Seg tr = Seg(pc);
    for (int i = mni; i < mni + n; i++) {
        tr.q();
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    a.assign(n, 0), b.assign(n, 0);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto x : a) a.push_back(x);
    for (auto x : b) b.push_back(x);
    vector<int> pc(1, 0);
    for (int i = 0; i < 2 * n; i++) {
        pc.push_back(pc.back() + a[i] - b[i]);
        if (pc[mni] > pc.back()) mni = i;
    }

    int l = 0, r = n + 1, m = (l + r) / 2;
    for (; r - l > 1; m = (r + l) / 2) {
        if (ch(a, pc, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}