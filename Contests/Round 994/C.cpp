// Codeforces Round 994: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i % 2;
    if (n % 2) {
        a[n - 1] = 2;
        vector<int> b(n);
        // for (auto x : a) cout << x << ' ';
        // cout << '\n';
        for (int i = 0; i < n; i++) b[i] = a[(i - x - 1 + n) % n];
        a = b;
    } else {
        if (a[x] == 0 && a[y] == 0) a[x] = 2;
        if (a[x] == 1 && a[y] == 1) a[x] = 2;
    }
    for (auto X : a) cout << X << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}