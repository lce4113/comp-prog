// Codeforces Round 1011: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (k == 0) {
        string b = a;
        reverse(b.begin(), b.end());
        cout << (a < b ? "YES\n" : "NO\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}