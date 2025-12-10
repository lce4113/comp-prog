// Codeforces Round 1011: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (a == b) {
        cout << "-1\n";
        return;
    }
    int x = 1ll << ((int)log2(a) + 1);
    cout << x - a << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}