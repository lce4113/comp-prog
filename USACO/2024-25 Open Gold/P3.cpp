#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

void solve() {
    int n, d, A, B;
    cin >> n >> d >> A >> B;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());

    int tot = 0;
    for (int i = B; i < A; i++) {
        tot += d - (min(a[B], a[i] + d) - a[i]);
        a[i] = min(a[B], a[i] + d);
    }

    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    // cout << tot << '\n';

    int c = 0, j = B;
    while (c < tot && j >= 1) {
        c += (a[j - 1] - a[j]) * (n - j);
        j--;
        // cout << c << ' ' << j << '\n';
    }

    vector<int> b = a;
    for (int i = B; i < A; i++) a[i] = a[B];

    // flatten
    int num = (j == 0 ? A : A - j);
    for (int i = A - num; i < A; i++) {
        tot -= a[A - num] - a[i];
        a[i] = a[A - num];
    }
    // distrib
    for (int i = A - num; i < A; i++) {
        a[i] += tot / num;
    }
    tot %= num;
    // left over
    for (int i = 0; i < tot; i++) {
        a[A - num + i]++;
    }

    // cout << i << '\n';

    // vector<int> pfs;
    // for (int j = 0; j < n; j++) {
    // }

    for (int i = B + 1; i < A; i++) a[i] -= b[i] - b[i - 1];

    for (auto x : a) cout << x << ' ';
    cout << '\n';

    int ans = 0;
    for (auto x : a) ans += x * x, ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}