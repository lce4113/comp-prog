// MITIT Spring 2025: Problem 1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n == 4) {
        cout << 2025 << '\n';
    } else if (n == 5) {
        cout << 42025 << '\n';
    } else if (n == 6) {
        cout << 632025 << '\n';
    } else if (n % 2) {
        string ans = "1";
        for (int i = 0; i < n / 2 - 2; i++) ans += '0';
        ans += "9";
        for (int i = 0; i < n / 2 - 3; i++) ans += '0';
        ans += "2025";
        cout << ans << '\n';
    } else {
        string ans = "16";
        for (int i = 0; i < n / 2 - 4; i++) ans += '0';
        ans += "36";
        for (int i = 0; i < n / 2 - 4; i++) ans += '0';
        ans += "2025";
        cout << ans << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // for (int i = 100; i < 1e4; i++) {
    //     if (i * i % 10000 == 2025) {
    //         cout << i << ' ' << i * i << '\n';
    //     }
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}
