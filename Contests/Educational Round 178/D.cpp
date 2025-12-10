// Codeforces Educational Round 178: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e7;
vector<int> lp(MAXN + 1), pr, prf(1, 0);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int sm = 0;
    for (auto x : a) sm += x;
    int cp = n, ci = 0;
    // cout << prf[cp] << '\n';
    while (sm < prf[cp] && cp >= 2) cp--, sm -= a[ci++];
    cout << ci << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

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
    for (auto x : pr) prf.push_back(prf.back() + x);
    // cout << pr.size() << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}