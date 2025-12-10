// Codeforces Global Round 29: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            if (c == 0) {
                if (i == 0) {
                    c = 1;
                } else {
                    c = 2;
                }
            } else if (c == 1) {
                c = 1;
            } else if (c == 2) {
                c = 1;
            } else if (c == 3) {
                c = 1;
            } else if (c == 4) {
                c = 5;
            } else if (c == 5) {
                c = 1;
            }
        } else {
            if (c == 1) {
                c = 3;
            } else if (c == 2) {
                c = 4;
            } else if (c == 3) {
                c = 0;
            } else if (c == 4) {
                cout << "NO\n";
                return;
            } else if (c == 5) {
                c = 0;
            }
        }
        // cout << c << ' ';
    }
    // cout << c << '\n';
    if (c == 4) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}