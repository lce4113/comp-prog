// Codeforces Round 961: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int mxn(int m, int x, int y, int nx, int ny) {
    // cout << x << ' ' << y << ' ' << nx << ' ' << ny << '\n';
    int ans = 0, M = m;
    int X = min(nx, m / x);
    m -= X * x, ans += X * x;
    int Y = min(ny, m / y);
    m -= Y * y, ans += Y * y;
    // cout << m << ' ' << M << ' ' << ans << ' ' << X << ' ' << Y << '\n';
    return min(M, ans + min(X, ny - Y));
}

// int mxn2(int m, int x, int y, int nx, int ny) {
//     int mn = 1e18;
//     // int nx = x.s, ny = mp.count(x.f + 1) ? mp[x.f + 1] : 0;
//     for (int i = 0; i <= nx; i++) {
//         int rem = m - i * x;
//         if (rem < 0) continue;
//         int M = y * min(rem / y, ny);
//         mn = min(mn, rem - M);
//     }
//     return m - mn;
// }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(n);
    for (auto &x : b) cin >> x;

    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]] = b[i];

    // cout << mxn(3, 1, 2, 3, 4) << '\n';

    int ans = -1;
    for (auto x : mp) {
        int c = mxn(m, x.f, x.f + 1, x.s, mp.count(x.f + 1) ? mp[x.f + 1] : 0);
        ans = max(ans, c);
    }
    cout << ans << '\n';
}

int32_t main() {
    // for (int i = 0; i <= 100; i++) {
    //     int mx = mxn(i, 4, 5, 9, 3);
    //     cout << setw(2) << mx << ' ';
    //     if (i % 5 == 4) cout << '\n';
    // }
    // cout << '\n';
    // for (int i1 = 1; i1 <= 20; i1++) {
    //     // for (int i2 = 1; i2 <= 100; i2++) {
    //     for (int i3 = 0; i3 <= 50; i3++) {
    //         for (int i4 = 0; i4 <= 50; i4++) {
    //             for (int i = 0; i <= 9 * 7 + 10 * 5 + 10; i++) {
    //                 int i2 = i1 + 1;
    //                 cout << i << ' ' << i1 << ' ' << i2 << ' ' << i3 << ' '
    //                      << i4 << '\n';
    //                 cout << mxn(i, i1, i2, i3, i4) << ' '
    //                      << mxn2(i, i1, i2, i3, i4) << '\n';
    //                 if (mxn(i, i1, i2, i3, i4) != mxn2(i, i1, i2, i3, i4)) {
    //                     cout << "ohno " << i << '\n';
    //                     return 0;
    //                 }
    //                 // cout << setw(3) << mx << ' ';
    //                 // if (i % 10 == 9) cout << '\n';
    //             }
    //         }
    //     }
    //     // }
    // }
    // cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}