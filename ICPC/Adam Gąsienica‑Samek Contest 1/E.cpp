#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e7;
vector<int> lp(MAXN + 1), pr;
map<int, vector<int>> mp;
vector<int> bad(1, 0), ones(1, 0);

int count(int num, int l, int r) {
    return lower_bound(mp[num].begin(), mp[num].end(), r) -
           lower_bound(mp[num].begin(), mp[num].end(), l);
}

struct Node {
    int v, l, r;
};

struct Tree {
    typedef Node T;
    static constexpr T unit = {-1, -1, -1};
    T f(T a, T b) {
        if (a.l == -1) return b;
        if (b.l == -1) return a;
        int ca = count(a.v, a.l, a.r) + count(a.v, b.l, b.r);
        int cb = count(b.v, a.l, a.r) + count(b.v, b.l, b.r);
        if (ca * 2 > bad[b.r] - bad[a.l]) return {a.v, a.l, b.r};
        if (cb * 2 > bad[b.r] - bad[a.l]) return {b.v, a.l, b.r};
        return {-1, a.l, b.r};
    }
    vector<T> s;
    int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void u(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T q(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        ones.push_back(ones.back() + (a[i] == 1));
        int num = 1, lst = -1;
        while (lp[a[i]]) {
            if (lp[a[i]] != lst) num *= lp[a[i]];
            lst = lp[a[i]];
            a[i] /= lp[a[i]];
        }
        if (lp[num] != num) num = -1;
        a[i] = num;
    }

    for (int i = 0; i < n; i++) {
        bad.push_back(bad.back() + (a[i] != -1));
        if (a[i] != -1) mp[a[i]].push_back(i);
    }

    Tree T(n);
    for (int i = 0; i < n; i++) T.u(i, {a[i], i, i + 1});

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        auto num = T.q(l, r);
        int onesc = ones[r] - ones[l];
        int badc = bad[r] - bad[l];
        int cnt = count(num.v, l, r);
        if (onesc + cnt == r - l) {
            cout << "-1\n";
            continue;
        }
        cout << max((badc + 1) / 2, cnt) + onesc << '\n';
    }
}

int32_t main() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    solve();
}