#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b > 0; a = (a * a) % MOD) {
        if (b % 2) ans = (ans * a) % MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(n + 1, 0);
    vector<pair<int, int>> mxs;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        int tw = 0;
        while (a[i] % 2 == 0) a[i] >>= 1, tw++;

        while (mxs.size() && mxs.back().f < a[i] * binexp(2, tw)) {
            sm = (sm - mxs.back().f * binexp(2, mxs.back().s)) % MOD;
            sm += MOD, sm %= MOD;
            sm = (sm + mxs.back().f) % MOD;
            tw += mxs.back().s;
            mxs.pop_back();
        }
        // for (auto x : mxs) cout << x.f << ' ' << x.s << '\n';
        sm = (sm + a[i] * binexp(2, tw)) % MOD;
        mxs.push_back({a[i], tw});
        cout << sm << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}