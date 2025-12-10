// Codeforces Round #969: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    map<int, int> adj;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1]++;
        adj[b - 1]++;
    }
    string zo;
    cin >> zo;
    // cout << zo << '\n';
    int z = 0, o = 0, r = 0, qs = 0;
    for (int i = 1; i < n; i++) {
        if (adj[i] == 1) {
            z += (zo[i] == '0');
            o += (zo[i] == '1');
            r += (zo[i] == '?');
        } else {
            qs += (zo[i] == '?');
        }
    }
    // cout << z << ' ' << o << ' ' << r << '\n';
    if (zo[0] == '?') {
        int ans = max(z, o);
        if (r % 2) {
            ans += r / 2 + ((qs % 2) & (z == o));
        } else {
            ans += r / 2;
        }
        cout << ans << '\n';
    } else {
        int ans = (zo[0] == '1' ? z : o);
        if (r % 2) {
            ans += r / 2 + 1;
        } else {
            ans += r / 2;
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
