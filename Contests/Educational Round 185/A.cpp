// Educational Codeforces Round 185: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 2) {
        cout << 9 << '\n';
        return;
    }
    int a1 = n * n + n * n - 1 + n * n - 2 + n * n - n - 1;
    int a2 = n * n - 1 + n * n - n + n * n - n - 1 + n * n - n - 2 + n * n -
             2 * n - 1;
    cout << max(a1, a2) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}