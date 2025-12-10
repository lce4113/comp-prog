// Codeforces Round #967: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    vector<int> a(n, -1);
    if (n % 2 == 0) {
        // for (int k = 1, i = 1; i < n; k++, i += 2) {
        //     a[i] = k;
        // }
        // for (int k = n / 2 + 1, i = n - 2; i >= 0; k++, i -= 2) {
        //     a[i] = k;
        // }
        cout << "-1\n";
        return;
    } else {
        for (int k = 1, i = 1; i < n; k++, i += 2) {
            a[i] = k;
        }
        for (int k = n / 2 + 1, i = n - 1; i >= 0; k++, i -= 2) {
            a[i] = k;
        }
    }
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}