// Codeforces Global Round 31: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    while (a < l) a += gcd(l, b);
    a -= gcd(l, b);
    cout << a << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}