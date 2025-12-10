// Codeforces Round 984: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}