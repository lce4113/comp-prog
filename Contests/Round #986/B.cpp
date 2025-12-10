// Codeforces Round #986: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, b, a;
    cin >> n >> b >> a;
    if (b == 0) {
        if (a >= n) {
            cout << n << '\n';
            return;
        }
        if (a >= n - 2) {
            cout << n - 1 << '\n';
            return;
        }
        cout << "-1\n";
        return;
    }
    int l = max(ceil((double)(n - a) / b), 0.0);
    cout << (n - l) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
