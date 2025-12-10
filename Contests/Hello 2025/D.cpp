// Codeforces Hello 2025: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Data {
    int sum, msum, mpref, msuf;
    Data(int x) : sum(x) { msum = mpref = msuf = max(0ll, x); }
    Data(Data a, Data b) {
        sum = a.sum + b.sum;
        mpref = max(a.mpref, a.sum + b.mpref);
        msuf = max(b.msuf, a.msuf + b.sum);
        msum = max({a.msum, b.msum, a.msuf + b.mpref});
    }
};

struct Seg {
    using F = Data (*)(Data, Data);
    F comb = [](Data a, Data b) { return Data(a, b); };
    int n, N;
    Data ID = Data(0);
    vector<Data> seg;

    Seg(vector<int> a) {
        vector<Data> b;
        for (auto x : a) b.push_back(Data(x));
        init(b);
    }
    Seg(vector<Data> a) { init(a); }
    Seg(vector<Data> a, Data _ID) : ID(_ID) { init(a); }
    Seg(vector<Data> a, F _comb) : comb(_comb) { init(a); }
    Seg(vector<Data> a, F _comb, Data _ID) : comb(_comb), ID(_ID) { init(a); }

    void init(vector<Data> a) {
        N = a.size();
        n = 1 << (int)ceil(log2(N));
        seg.assign(n, ID);
        for (auto x : a) seg.push_back(x);
        while ((int)seg.size() < 2 * n) seg.push_back(ID);
        for (int i = n - 1; i >= 1; i--) calc(i);
    }

    void calc(int i) { seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }

    Data get(int i) {
        assert(i >= 0), assert(i < N);
        return seg[i + n];
    }

    void u(int i, int val) { u(i, Data(val)); }
    void u(int i, Data val) {
        assert(i >= 0), assert(i < N);
        i = i + n, seg[i] = val;
        for (i /= 2; i; i /= 2) calc(i);
    }

    Data q(int L) { return q(L, L + 1); }
    Data q(int L, int R) { return q(L, R, 0, n, 1); }
    Data q(int L, int R, int l, int r, int i) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return ID;
        if (l >= L && r <= R) return seg[i];
        int m = (l + r) / 2;
        Data ans = ID;
        ans = comb(ans, q(L, R, l, m, 2 * i));
        ans = comb(ans, q(L, R, m, r, 2 * i + 1));
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), as, ap;
    for (auto &x : a) cin >> x;

    as = ap = a;
    for (int i = 0; i < n; i++) as[i] -= i, ap[i] += i;
    vector<int> asd(n - 1), apd(n - 1);
    for (int i = 0; i < n - 1; i++) {
        asd[i] = as[i + 1] - as[i];
        apd[i] = ap[i] - ap[i + 1];
    }
    // for (auto x : asd) cout << x << ' ';
    // cout << '\n';
    // for (auto x : apd) cout << x << ' ';
    // cout << '\n';

    Seg mxs = Seg(asd);
    Seg mxp = Seg(apd);

    // vector<pair<int, int>> mp(n);
    // multiset<int> ms;
    // for (int i = 0; i < n; i++) {
    //     int cp = mxp.q(0, i) - ap[i];
    //     int cs = mxs.q(i + 1, n) - as[i];
    //     ms.insert(cp), ms.insert(cs);
    //     mp[i] = {cp, cs};
    // }

    cout << max(mxs.q(0, n - 1).msum, mxp.q(0, n - 1).msum) << '\n';

    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;

        as[p] = x - p, ap[p] = x + p;
        if (p - 1 >= 0) mxs.u(p - 1, as[p] - as[p - 1]);
        if (p < n - 1) mxs.u(p, as[p + 1] - as[p]);
        if (p - 1 >= 0) mxp.u(p - 1, ap[p - 1] - ap[p]);
        if (p < n - 1) mxp.u(p, ap[p] - ap[p + 1]);

        cout << max(mxs.q(0, n - 1).msum, mxp.q(0, n - 1).msum) << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}