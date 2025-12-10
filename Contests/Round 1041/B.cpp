// Codeforces Round 1041: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    // if (k == 1 || k == n) {
    //     cout << "1\n";
    //     return;
    // };
    int L = k - 1, R = k - 1;
    while (L >= 0 && a[L] != '#') L--;
    L++;
    while (R < n && a[R] != '#') R++;
    R--;
    int l1 = L + 1, l2 = k;
    int r1 = n - R, r2 = n - k + 1;
    // cout << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << '\n';
    cout << max(min(l1, r2), min(l2, r1)) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}