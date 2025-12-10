// Meta Hacker Cup 2025 Round 1: Problem B2

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int N = 1e7;

vector<int> lp(N + 1), pr;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int comb(int n, int r) {
    int ans = 1;
    for (int i = 0; i < r; i++) {
        ans *= (n - i) % MOD, ans %= MOD;
        ans *= binexp(i + 1), ans %= MOD;
    }
    return ans;
}

map<int, int> pf(int n) {
    map<int, int> res;
    for (int j = 0; n != 1 && j < pr.size(); j++) {
        while (n % pr[j] == 0) n /= pr[j], res[pr[j]]++;
    }
    if (n != 1) res[n]++;
    return res;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    auto P = pf(b);
    int cnt = 1;
    for (auto x : P) cnt *= x.s + 1;
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        int I = i;
        map<int, int> C1, C2;
        int c1 = 1, c2 = 1;
        for (auto x : P) {
            int tot = I % (x.s + 1);
            C1[x.f] = tot, C2[x.f] = x.s - tot;
            c1 *= pow(x.f, tot), c2 *= pow(x.f, tot);
            I /= x.s + 1;
        }
        if (c1 > a) continue;
        int tot = 1;
        for (auto x : C1) {
            tot *= comb(n + x.s - 1, x.s), tot %= MOD;
        }
        for (auto x : C2) {
            tot *= comb(n + x.s - 1, x.s), tot %= MOD;
        }
        ans += tot, ans %= MOD;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= N; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}