#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int check(int x) { return x - (int)sqrt(x); }

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n * 2 + 1, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        // cout << l << ' ' << r << ' ' << m << ' ' << check(m) << '\n';
        if (check(m) < n)
            l = m;
        else
            r = m;
    }
    cout << r << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}