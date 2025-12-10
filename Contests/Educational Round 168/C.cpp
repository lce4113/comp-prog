// Codeforces Educational Round 168: Problem C

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
    int ans = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '_') {
            if (c > 0) a[i] = ')';
            if (c == 0) a[i] = '(';
        }
        if (a[i] == '(') c++;
        if (a[i] == ')') c--;
        ans += c;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}