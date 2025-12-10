// Codeforces Educational Round 184: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    if (n == 1 && a[0] == '*') {
        cout << 1 << '\n';
        return;
    }
    for (auto x : a) {
    }
    int L = 0, c = n, C = -1;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && a[i] == '>' && a[i + 1] == '<') {
            cout << -1 << '\n';
            return;
        }
        if (a[i] == '*') {
            if (i != 0 && a[i - 1] != '<') {
                cout << -1 << '\n';
                return;
            }
            if (i != n - 1 && a[i + 1] != '>') {
                cout << -1 << '\n';
                return;
            }
        }
        if (a[i] == '>' && c == n) c = i;
        if (a[i] == '<') C = i;
    }
    cout << max(n - C - 1, c) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}