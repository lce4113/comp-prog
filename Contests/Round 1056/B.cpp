// Codeforces Round 1056: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == n * n) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "U";
            }
            cout << '\n';
        }
        return;
    }
    if (k == n * n - 1) {
        cout << "No\n";
        return;
    }
    k = n * n - k;
    vector<string> a(n, string(n, 'U'));
    a[n - 1][0] = 'R';
    a[n - 1][1] = 'L';
    k -= 2;
    for (int i = 2; k > 0 && i < n; i++, k--) {
        a[n - 1][i] = 'L';
    }
    for (int i = n - 2; i >= 0 && k > 0; i--) {
        for (int j = 0; j < n && k > 0; j++, k--) {
            a[i][j] = 'D';
        }
    }
    cout << "Yes\n";
    for (auto x : a) cout << x << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}