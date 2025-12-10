// Codeforces Round 1057: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int N = 1e7;
vector<int> lp(N + 1), pr;

int count(int n, int p) {
    int ans = 0;
    while (n) {
        ans += n / p;
        n /= p;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int prev = *(--upper_bound(pr.begin(), pr.end(), n));
    set<int> prs;
    int ans = 0;
    for (int c = prev + 1; c <= n; c++) {
        int C = c;
        while (C != 1) {
            prs.insert(lp[C]);
            C /= lp[C];
        }
    }
    for (int c = prev; c < n; c++) {
        int my = 1e9;
        for (auto p : prs) {
            if (p > m || p > n) break;
            int P = 1, cp = 0;
            int x = count(n, p), y = count(c, p);
            if (x == y) continue;
            while (P * p <= m && cp + 1 <= x) {
                P *= p, cp++;
                if (x / cp != y / cp) my = min(my, y / cp);
            }
        }
        ans += my;
    }
    cout << ans << '\n';
}

int32_t main() {
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
    while (t--) solve();
}