// Codeforces Round 1022: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int h = n / 2;
    if (n % 2) {
        cout << (h * h + h * (h + 1) + h) / 2 + 1 << '\n';
    } else {
        cout << (h * n) / 2 + 1 << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}