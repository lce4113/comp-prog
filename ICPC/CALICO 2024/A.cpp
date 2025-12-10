// CALICO 2024: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string oreo;
    cin >> oreo;
    int n = oreo.size();
    // cout << oreo << '\n';
    for (int i = 0; i < n; i++) {
        if (oreo[i] == '&') {
            cout << '\n';
        } else if (oreo[i] == 'O') {
            cout << "[###OREO###]\n";
        } else if (oreo.substr(i, 2) == "RE") {
            cout << "[--------]\n";
            i++;
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}