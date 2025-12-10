// CSES Sliding Window Problems: Sliding Window Sum

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    int cur = 0, it1 = x, it2 = x;
    int i = 0;
    for (; i < k; i++, it2 = (it2 * a + b) % c) cur += it2;
    int ans = cur;
    for (; i < n; i++, it1 = (it1 * a + b) % c, it2 = (it2 * a + b) % c) {
        cur += it2, cur -= it1;
        ans ^= cur;
    }
    cout << ans << '\n';
}