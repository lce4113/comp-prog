// Codeforces Round 1000: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 1 && b == 1) {
        cout << "1\n";
        return;
    }
    cout << b - a << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}