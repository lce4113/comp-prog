// CSES Mathematics: Christmas Party

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int32_t main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    vector<int> ans(n + 1);
    ans[2] = 1;
    for (int i = 3; i <= n; i++) {
        ans[i] = ans[i - 2] * (i - 1) + ans[i - 1] * (i - 1), ans[i] %= MOD;
    }
    cout << ans[n] << '\n';
}