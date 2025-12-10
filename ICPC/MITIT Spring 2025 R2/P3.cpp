// MITIT Spring Invitational Qualification Round 2
// P1

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string ans = "rr";
    for (int i = 0; i < n - 2; i++) {
        if (a[i] != 'r' && a[i + 1] != 'r' && a[i + 2] != 'r') {
            ans += 'r';
        } else if (a[i] != 'g' && a[i + 1] != 'g' && a[i + 2] != 'g') {
            ans += 'g';
        } else if (a[i] != 'b' && a[i + 1] != 'b' && a[i + 2] != 'b') {
            ans += 'b';
        } else {
            ans += 'y';
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}