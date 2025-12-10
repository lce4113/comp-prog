// Codeforces Round 1012: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == '0') continue;
            bool val1 = true;
            for (int k = i; k >= 0; k--) {
                if (a[k][j] == '0') {
                    val1 = false;
                    break;
                }
            }
            bool val2 = true;
            for (int k = j; k >= 0; k--) {
                if (a[i][k] == '0') {
                    val2 = false;
                    break;
                }
            }
            if (!val1 && !val2) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}