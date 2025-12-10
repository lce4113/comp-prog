// Codeforces Round 997: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n == 6) {
        cout << "1 1 2 3 1 2\n";
        return;
    }
    for (int i = 1; i <= (n + 1) / 2; i++) cout << i << ' ';
    for (int i = 1; i <= n - (n + 1) / 2; i++) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}