// Spring 2025 Columbia University Local Contest
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1, j = n - 3; j >= 1; i++, j--) {
        ans += i * j;
    }
    ans *= n, ans /= 4;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}