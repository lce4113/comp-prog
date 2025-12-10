// Codeforces Round #988: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n <= 4) {
        cout << "-1\n";
        return;
    }
    if (n % 2) {
        for (int i = 1; i <= n; i += 2) {
            cout << i << ' ';
        }
        int x;
        if (n % 3 == 1) {
            x = n - 5;
        } else {
            x = n - (3 - n % 3);
        }
        cout << x << ' ';
        for (int i = 2; i <= n; i += 2) {
            if (i == x) continue;
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        for (int i = 2; i <= n; i += 2) {
            cout << i << ' ';
        }
        int x;
        if (n % 3 == 1) {
            x = n - 5;
        } else {
            x = n - (3 - n % 3);
        }
        cout << x << ' ';
        for (int i = 1; i <= n; i += 2) {
            if (i == x) continue;
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}