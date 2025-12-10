// Codeforces Round 1034: Problem D

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
    int c1 = 0;
    for (auto x : a) c1 += x == '1';
    if (c1 <= k) {
        cout << "Alice\n";
        return;
    }
    if (2 * k > n) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}