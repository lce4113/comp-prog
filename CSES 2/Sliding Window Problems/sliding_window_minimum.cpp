// CSES Sliding Window Problems: Sliding Window Minimum

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e7;
int bin[MAXN], nbin[MAXN];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    for (int i = 0, cur = x; i < n; i++, cur = (cur * a + b) % c) {
        bin[i] = cur;
    }
    int K = __lg(k);
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            nbin[j] = min(bin[j], bin[j + (1 << (i - 1))]);
        }
        swap(bin, nbin);
    }

    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
        ans ^= min(bin[i], bin[i + k - (1 << K)]);
    }
    cout << ans << '\n';
}