// Codeforces Round 1002: Problem B
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (k == n) {
        int c = 1;
        for (int i = 1; i < n; i += 2) {
            if (a[i] == c)
                c++;
            else {
                cout << c << '\n';
                return;
            }
        }
        cout << c << '\n';
        return;
    }

    for (int i = 1; i < n - (k - 2); i++) {
        // cout << i << ' ' << a[i] << '\n';
        if (a[i] != 1) {
            cout << "1\n";
            return;
        }
    }

    cout << "2\n";
    return;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}