// CSES Intro Problems: Gray Code

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string b;
    for (int i = 0; i < n; i++) b += '0';
    vector<string> a(1 << n, b);
    for (int i = 0; i < n; i++) {
        for (int j = (1 << i); j < (1 << n); j += (1 << (i + 2))) {
            for (int k = 0; k < (1 << (i + 1)) && j + k < (1 << n); k++) {
                a[j + k][i] = '1';
            }
        }
    }
    for (auto &x : a) {
        reverse(x.begin(), x.end());
        cout << x << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
