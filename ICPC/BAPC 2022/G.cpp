// BAPC 2025: Problem G

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
int n, k;
unordered_map<int, int> dp[8];
vector<int> cnt(k);

int conv() {
    int ans = 0;
    for (int i = 0, p = 1; i < cnt.size(); i++, p *= 8) ans += cnt[i] * p;
    return ans;
}

int rec(int rem) {
    if (dp[rem].count(conv())) return dp[rem][conv()];
    int ans = INF;
    for (int i = 1; i < k; i++) {
        if (cnt[i] == 0) continue;
        for (int j = 1; j <= i; j++) {
            if (rem + j > k) continue;
            cnt -= pow(8, i);
            if (i - j) cnt += pow(8, i - j);
            ans = min(ans, (j != i) + rec(cnt, (rem + j) % k));
            cnt += pow(8, i);
            if (i - j) cnt -= pow(8, i - j);
        }
    }
    dp[rem][conv()] = ans;
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += (x - 1) / k;
        x %= k;
        if (x) cnt[x]++;
    }
    for (int i = 1, j = k - 1; i < j; i++, j--) {
        int c = min(cnt[i], cnt[j]);
        cnt[i] -= c, cnt[j] -= c;
    }

    dp[0][0] = 0;
    cout << ans + rec(cnt, 0) << '\n';
}