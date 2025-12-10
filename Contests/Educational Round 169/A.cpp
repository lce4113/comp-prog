// Codeforces Educational Round 169: Problem A

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
    sort(a.begin(), a.end());
    if (n > 2)
        cout << "NO\n";
    else if (a[1] - a[0] <= 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}