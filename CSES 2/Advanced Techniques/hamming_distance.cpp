// CSES Advanced Techniques: Hamming Distance

#include <bits/stdc++.h>
using namespace std;

int bin(string &b) {
    int n = b.size();
    int ans = 0;
    for (int i = n - 1, e = 1; i >= 0; i--, e *= 2) {
        ans += (b[i] == '1') * e;
    }
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) {
        string b;
        cin >> b;
        x = bin(b);
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
        }
    }

    cout << ans << '\n';
}