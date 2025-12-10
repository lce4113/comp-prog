#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

int n;
ll a[40];
pair<ll, ll> lv[1 << 20] = {}, rv[1 << 20] = {};

void out(vector<int> &v1, vector<int> &v2) {
    set<int> o1(v1.begin(), v1.end());
    set<int> o2(v2.begin(), v2.end());
    vector<int> rem;
    for (auto x : o1) {
        if (o2.count(x)) rem.push_back(x);
    }
    for (auto x : rem) o1.erase(x), o2.erase(x);
    cout << o1.size() << '\n';
    for (auto x : o1) cout << a[x] << ' ';
    cout << '\n';
    cout << o2.size() << '\n';
    for (auto x : o2) cout << a[x] << ' ';
    cout << '\n';
}

vector<int> bin(ll num) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (num & (1ll << i)) ans.push_back(i);
    }
    return ans;
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    set<ll> S;
    for (int i = 0; i < n; i++) {
        if (S.count(a[i])) {
            cout << "1\n" << a[i] << "\n" << "1\n" << a[i] << "\n";
            return 0;
        }
        S.insert(a[i]);
    }

    int ls = (n + 1) / 2, rs = n - ls;
    int lvs = 1 << ls, rvs = 1 << rs;
    for (int i = 1; i < lvs; i++) {
        int lst = __builtin_ctz(i);
        lv[i] = {lv[i ^ (1 << lst)].f + a[lst], i};
    }
    sort(lv, lv + lvs);
    for (int i = 0; i < lvs - 1; i++) {
        if (lv[i].f == lv[i + 1].f) {
            auto o1 = bin(lv[i].s);
            auto o2 = bin(lv[i + 1].s);
            out(o1, o2);
            return 0;
        }
    }

    for (int i = 1; i < rvs; i++) {
        int lst = __builtin_ctz(i);
        rv[i] = {rv[i ^ (1 << lst)].f + a[lst + ls], i};
    }
    sort(rv, rv + rvs);
    for (int i = 0; i < rvs - 1; i++) {
        if (rv[i].f == rv[i + 1].f) {
            auto o1 = bin(rv[i].s);
            auto o2 = bin(rv[i + 1].s);
            out(o1, o2);
            return 0;
        }
    }

    ll l = 1, r = (1ll << n) - 2, cur = (1ll << n);
    while (r - l > 0) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        int lp = 0, rp = 0;
        for (int i = lvs - 1; i >= 0; i--) {
            while (rp < rvs && rv[rp].f <= m - lv[i].f) rp++;
            while (lp < rvs && rv[lp].f < l - lv[i].f) lp++;
            cnt += rp - lp;
        }
        if (cnt > m - l + 1) {
            cur = cnt;
            r = m;
        } else {
            cur = cur - cnt;
            l = m + 1;
        }
    }

    vector<pair<int, int>> is;
    for (int lp = lvs - 1, rp = 0; lp >= 0 && rp < rvs;) {
        if (lv[lp].f + rv[rp].f > l) {
            lp--;
        } else if (lv[lp].f + rv[rp].f < l) {
            rp++;
        } else {
            is.push_back({lv[lp].s, rv[rp].s});
            if (is.size() == 2) break;
            lp--;
            rp++;
        }
    }

    vector<int> o1 = bin(is[0].f), o2 = bin(is[1].f);
    auto c = bin(is[0].s);
    for (auto v : c) o1.push_back(v + (n + 1) / 2);
    c = bin(is[1].s);
    for (auto v : c) o2.push_back(v + (n + 1) / 2);
    out(o1, o2);
}