// Codeforces Round 985: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int one = 0, zero = 0;
    for (auto x : a) {
        if (x == '1')
            one++;
        else
            zero++;
    }
    // cout << one << ' ' << zero << '\n';
    for (auto x : b) {
        if (zero == 0 || one == 0) {
            cout << "NO\n";
            return;
        }
        if (x == '1')
            zero--;
        else
            one--;
        // cout << one << ' ' << zero << '\n';
    }
    cout << "YES\n";
    // cout << one << ' ' << zero << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}