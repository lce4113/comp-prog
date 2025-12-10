// Codeforces Round 999: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int e = 0, o = 0;
    for (auto &x : a) {
        cin >> x;
        e += (x % 2 == 0);
        o += (x % 2 == 1);
    }
    int ans = 0;
    if (e >= 1) ans++;
    ans += o;
    if (o == n) ans--;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}