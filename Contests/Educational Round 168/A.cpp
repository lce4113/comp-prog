// Codeforces Educational Round 168: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();

    string ans = "";
    bool B = true;
    for (int i = 0; i < n; i++) {
        ans += a[i];
        if (B && i != n - 1 && a[i] == a[i + 1]) {
            ans += (a[i] == 'a' ? "b" : "a");
            B = false;
        }
    }
    if (B) ans += (a[n - 1] == 'a' ? "b" : "a");
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}