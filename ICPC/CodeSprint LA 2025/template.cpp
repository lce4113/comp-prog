#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

// sry i accidentally joined from the wrong account
// redoing wrong answers on this one

void solve() {
    int n, m;
    cin >> n >> m;
    if (gcd(n, m) != 1) {
        cout << "Yes\n";
        return;
    }
    int N = n;
    while (N % 2 == 0) N /= 2;
    if (N == 1) {
        cout << "No\n";
        return;
    }

    int o = N;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        if (i % 2) o = min(o, i);
        if ((n / i) % 2) o = min(o, n / i);
    }
    cout << (m < o || m > n - o ? "No\n" : "Yes\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}