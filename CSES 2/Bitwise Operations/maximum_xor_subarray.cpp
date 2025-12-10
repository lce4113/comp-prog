// CSES Bitwise Operations: Maximum Xor Subarray

#include <bits/stdc++.h>
using namespace std;

const int B = 30;
set<int> L({0});

bool has(int l, int r) {
    auto it = L.lower_bound(l);
    return it != L.end() && *it < r;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        pre ^= a[i];
        int c = 0;
        for (int e = B - 1; e >= 0; e--) {
            if (pre & (1 << e)) {
                if (!has(c, c + (1 << e))) c += (1 << e);
            } else {
                if (has(c + (1 << e), c + 2 * (1 << e))) c += (1 << e);
            }
        }
        ans = max(ans, pre ^ c);
        L.insert(pre);
    }
    cout << ans << '\n';
}