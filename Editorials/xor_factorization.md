# Codeforces Global Round 31: Problem C. XOR Factorization

**Link:** https://codeforces.com/contest/2180/problem/C

When `k` is odd, we set all `a_i` to `n`. This is clearly optimal.

When `k` is even, the following is my construction. Set `a_i` to
- [if `i` <= # of 1-bits in `n`] `n ^ (1 << b) | ((1 << b) - 1)` where `b` is index of `i`th 1-bit in `a_i`
- [if `i` > # of 1-bits in `n`] `n`

Let xor total `a_1 ^ a_2 ^...^ a_k` be `xr`. If `xr` is not `n`, set `a_1` to `a_1 ^ xr ^ n` to make `xr = n`.

Lowkey don't wanna prove this.

<!-- We show this is optimal for each bit.
- [<u>1</u>0010110] It is never optimal to have less than `k-1` of the first 1-bit of `n` (from highest to lowest).
- [1<u>00</u>10110] Consider the 0-bits between the first and second 1-bits. Suppose two `a_i` have a 1-bit in one of these positions. By pigeonhole, some `a_i` must have both first 1-bit and some 0-bit after that set to 1, which implies it is greater than `n`. So, no `a_i` can have a 1-bit in these positions.
- [100<u>1</u>0110] This bit can have at most -->

## Reflection

In contest, I tried a couple solutions for even `k` that seemed correct but weren't:
- Set `k-1` to `n` and one to 0.
- Let first two 1-bits in `n` be index `b1` and `b2`. Set `k-2` to `n`, one to `n ^ (1 << b2) | ((1 << b2) - 1)`, and one to `n ^ (1 << b1) ^ ((1 << (b2+1)) - 1)`. I basically thought you only had to set two values to less than `n`, but this fails to `n=30` and `k=4`, which is really difficult to find.

My main mistake was not stress testing after spending a while debugging. Need to get back into stress testing. I also did not check standings so I did not see how many people had wrong answer, which could have made me realize stress testing is the move.


## [Code](../Contests/Global%20Round%2031/C2.cpp)
```cpp
// Codeforces Global Round 31: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

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