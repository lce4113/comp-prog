// ASC 47: Problem B

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

map<array<ll, 3>, ll> mp;

string B(ll v, int n) {
    string c;
    for (int i = 0; i < n; i++) {
        c += (v & 1) ? 'b' : 'a';
        v >>= 1;
    }
    reverse(c.begin(), c.end());
    return c;
}

ll big(int n) {
    ll c = (ll)1 << (n - 1);
    return c - 1 + c;
}

// get [l,r) substring
ll sub(ll v, int l, int r, int n) {
    int L = n - r, R = n - l;
    return (v & big(R)) >> L;
}

// is v borderless
bool bdl(ll v, int n) {
    for (int i = 1; i <= n / 2; i++) {
        if (sub(v, 0, i, n) == sub(v, n - i, n, n)) return 0;
    }
    return 1;
}

// number of borderless strings with prefix pre
ll cnt(ll pre, int m, int n) {
    if (mp.count({pre, m, n})) return mp[{pre, m, n}];
    ll tot = ((ll)1 << (n - m));
    for (int i = 1; i <= m && i <= n / 2; i++) {
        if (bdl(sub(pre, 0, i, m), i)) {
            if (n < i + m) {
                int len = i - (n - m);
                if (sub(pre, 0, len, m) == sub(pre, m - len, m, m)) tot--;
            } else {
                tot -= (ll)1 << (n - i - m);
            }
        }
    }
    for (int i = m + 1; i <= n / 2; i++) {
        tot -= cnt(pre, m, i) * ((ll)1 << (n - 2 * i));
    }
    mp[{pre, m, n}] = tot;
    return tot;
}

// number of borderless strings <= me
ll num(ll c, int n) {
    ll res = bdl(c, n);
    for (int i = 0; i < n; i++) {
        if (sub(c, i, i + 1, n)) {
            ll sb = sub(c, 0, i, n);
            res += cnt(sb << 1, i + 1, n);
        }
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef ONLINE_JUDGE
    ifstream cin("borderless.in");
    ofstream cout("borderless.out");
#endif

    ll n, k;
    while (1) {
        cin >> n >> k;
        if (n == 0 && k == 0) return 0;
        ll l = 0, r = big(n);
        while (r - l > 0) {
            ll m = l + (r - l) / 2;
            if (num(m, n) >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << B(r, n) << '\n';
    }
}