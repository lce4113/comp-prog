// Codeforces Educational Round 180: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i + 1] - a[i]) <= 1) {
            cout << "0\n";
            return;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if ((a[i - 1] > a[i] && a[i] < a[i + 1]) ||
            (a[i - 1] < a[i] && a[i] > a[i + 1])) {
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}