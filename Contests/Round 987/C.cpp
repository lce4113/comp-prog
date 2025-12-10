// Codeforces Round 987: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n % 2 && n < 27) {
        cout << "-1\n";
        return;
    }
    if (n % 2 == 0) {
        for (int k = 1; k <= n / 2; k++) {
            cout << k << ' ' << k << ' ';
        }
        cout << '\n';
        return;
    }
    cout << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 13 12 12 1 13 ";
    for (int i = 28, k = 14; i <= n; i += 2, k++) {
        cout << k << ' ' << k << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}