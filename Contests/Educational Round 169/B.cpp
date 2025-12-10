// Codeforces Educational Round 169: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    for (int i = 1; i < 100; i++) {
        bool a1 = i >= l1 && i <= r1;
        bool b1 = (i + 1) >= l1 && (i + 1) <= r1;
        bool a2 = i >= l2 && i <= r2;
        bool b2 = (i + 1) >= l2 && (i + 1) <= r2;
        if ((a1 && b2) || (a2 && b1)) ans++;
    }
    cout << max(1, ans) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}