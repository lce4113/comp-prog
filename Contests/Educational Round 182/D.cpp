// Codeforces Educational Round 182: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5;

void solve() {
    int n, y;
    cin >> n >> y;
    vector<int> a(n), d(MAXN + 1), cnt(MAXN + 1), cntp(MAXN + 2), sm(MAXN + 1);
    for (auto &x : a) cin >> x;

    for (auto x : a) cnt[x]++;
    for (int i = 0; i <= MAXN; i++) cntp[i + 1] = cntp[i] + cnt[i];
    for (int i = 2; i <= MAXN; i++) {
        for (int j = 1; i * (j - 1) <= MAXN; j++) {
            int rng = cntp[min(MAXN, i * j) + 1] - cntp[i * (j - 1) + 1];
            d[i] += min(cnt[j], rng);
            sm[i] += j * rng;
        }
    }
    int ans = -1e18;
    for (int i = 2; i <= MAXN; i++) {
        int c = sm[i] - y * (n - d[i]);
        ans = max(ans, c);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}