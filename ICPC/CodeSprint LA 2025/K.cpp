#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct MinTree {
    typedef int T;
    static constexpr T unit = 1e18;
    T f(T x, T y) { return min(x, y); }
    vector<T> a;
    int n;
    MinTree(int n) : a(2 * n, unit), n(n) {}
    void u(int pos, T val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    T q(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, a[b++]);
            if (e % 2) rb = f(a[--e], rb);
        }
        return f(ra, rb);
    }
};

struct SumTree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T x, T y) { return x + y; }
    vector<T> a;
    int n;
    SumTree(int n) : a(2 * n, unit), n(n) {}
    void u(int pos, T val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    T q(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, a[b++]);
            if (e % 2) rb = f(a[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), a2;
    for (auto &x : a) cin >> x;
    for (auto &x : a) x--;
    a2 = a;
    for (auto x : a) a2.push_back(x);

    vector<set<int>> pos(n);
    for (auto &x : pos) x.insert(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        pos[a2[i]].insert(i);
    }

    MinTree mseg(2 * n);
    for (auto &x : pos) {
        for (auto prev = x.begin(), it = ++x.begin(); it != x.end();
             it++, prev++) {
            mseg.u(*prev, *it);
        }
    }

    SumTree sseg(2 * n);
    for (auto &x : pos) {
        if (x.size() / 2 <= 0) continue;
        sseg.u(*x.begin() + n, x.size() / 2);
        sseg.u(*(++x.rbegin()) - n, x.size() / 2);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {
            int num;
            cin >> num;
            num--;
            if (pos[num].size() / 2 <= 1) {
                cout << "-1\n";
                continue;
            }
            int r = *pos[num].begin() + n, l = *(++pos[num].rbegin()) - n + 1;
            int nxt = mseg.q(l, r);
            if (nxt < r) {
                cout << "-1\n";
                continue;
            }
            int sm = sseg.q(l, r);
            cout << sm - (r - l) << '\n';
        } else {
            int nxt, p;
            cin >> nxt >> p;
            nxt--, p--;
            int prev = a2[p];
            a2[p] = nxt, a2[p + n] = nxt;
            pos[prev].erase(p), pos[prev].erase(p + n);
            pos[nxt].insert(p), pos[nxt].insert(p + n);

            // update mseg prev
            auto aft = pos[prev].upper_bound(p), bef = aft;
            if (aft != pos[prev].begin()) mseg.u(*(--bef), *aft);
            aft = pos[prev].upper_bound(p + n), bef = aft;
            if (aft != pos[prev].begin()) mseg.u(*(--bef), *aft);

            // update mseg nxt
            aft = pos[nxt].upper_bound(p), bef = aft;
            mseg.u(p, *aft);
            aft--, bef--;
            if (aft != pos[nxt].begin()) mseg.u(*(--bef), *aft);
            aft = pos[nxt].upper_bound(p + n), bef = aft;
            mseg.u(p + n, *aft);
            aft--, bef--;
            if (aft != pos[nxt].begin()) mseg.u(*(--bef), *aft);

            // update sseg prev
            if (pos[prev].size() > 1) {
                sseg.u(*pos[prev].begin() + n, pos[prev].size() / 2);
                sseg.u(*(++pos[prev].rbegin()) - n, pos[prev].size() / 2);
            }

            // update sseg nxt
            if (pos[nxt].size() > 1) {
                sseg.u(*pos[nxt].begin() + n, pos[nxt].size() / 2);
                sseg.u(*(++pos[nxt].rbegin()) - n, pos[nxt].size() / 2);
            }
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}