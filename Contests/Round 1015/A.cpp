// Codeforces Round 1015: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }

    cout << n << ' ';
    for (int i = 1; i < n; i++) {
        cout << i << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}