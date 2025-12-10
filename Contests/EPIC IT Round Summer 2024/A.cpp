

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    cout << n * k - (k - 1) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}