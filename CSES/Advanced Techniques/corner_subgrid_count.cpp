// CSES Advanced Techniques: Corner Subgrid Count
#include <bits/stdc++.h>
#ifndef __APPLE__
#pragma GCC target("popcnt")
#endif
using namespace std;

const int MAXN = 3e3;
bitset<MAXN> a[MAXN];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto c = a[i] & a[j];
            int num = c.count();
            ans += num * (num - 1);
        }
    }

    cout << ans / 2 << '\n';
}