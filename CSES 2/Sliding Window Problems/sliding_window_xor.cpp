// CSES Sliding Window Problems: Sliding Window Xor

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e7;
int arr[MAXN];
int pfs[MAXN + 1];

int32_t main() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    for (int i = 0, cur = x; i < n; i++, cur = (cur * a + b) % c) arr[i] = cur;
    int cur = 0;
    for (int i = 0; i < k; i++) cur ^= arr[i];
    int ans = cur;
    for (int l = 0, r = k; r < n; l++, r++) {
        cur ^= arr[l];
        cur ^= arr[r];
        ans ^= cur;
    }
    cout << ans << '\n';
}