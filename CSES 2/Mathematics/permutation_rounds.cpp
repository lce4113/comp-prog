// CSES Mathematics: Permutation Rounds

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<int> lp(MAXN + 1), pr;

map<int, int> pfac(int n) {
    map<int, int> res;
    while (n != 1) res[lp[n]]++, n /= lp[n];
    return res;
}

int32_t main() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {
        cin >> x;
        x--;
    }
    map<int, int> mp;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int c = i, len = 0;
        do {
            c = p[c];
            len++;
            vis[c] = 1;
        } while (c != i);
        auto P = pfac(len);
        for (auto x : P) mp[x.f] = max(mp[x.f], x.s);
    }

    int ans = 1;
    for (auto x : mp) {
        while (x.s--) ans *= x.f, ans %= MOD;
    }
    cout << ans << '\n';
}