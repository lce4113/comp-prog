# XOR Factorization

**Link:** https://codeforces.com/contest/2180/problem/C

# Solution

First, when `k` is odd, we clearly set all `a_i` to 

Code: 
```cpp
// Codeforces Global Round 31: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 0; i < k; i++) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> ans;
    for (int i = 0, N = n; N && i < k; i++) {
        ans.push_back(n ^ (1 << __lg(N)) | ((1 << __lg(N)) - 1));
        N -= 1 << __lg(N);
    }
    while (ans.size() < k) ans.push_back(n);
    int xr = 0;
    for (auto x : ans) xr ^= x;
    ans[0] ^= xr ^ n;
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
```