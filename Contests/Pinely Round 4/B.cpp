// Codeforces Pinely Round 4: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (auto &x : a) cin >> x;

    for (int i = 0; i < n - 3; i += 2) {
        // cout << "op: ";
        // cout << a[i] << ' ' << a[i + 2] << '\n';
        int x = a[i] & a[i + 2];
        if ((x & ~a[i + 1]) != 0) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i < n - 3; i += 2) {
        // cout << "op: ";
        // cout << a[i] << ' ' << a[i + 2] << '\n';
        int x = a[i] & a[i + 2];
        if ((x & ~a[i + 1]) != 0) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; i++) {
        ans[i + 1] = a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ans[i] = ans[i] | a[i];
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}