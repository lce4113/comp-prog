// Codeforces Round 1030: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string ans;
    for (int i = 0; i < n; i++) ans += '0';
    for (int i = 0; i < k; i++) {
        ans[i] = '1';
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}