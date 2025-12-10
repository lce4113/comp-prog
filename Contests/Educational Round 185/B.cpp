// Educational Codeforces Round 185: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int a1 = 0, a2 = reduce(a.begin(), a.end());
    for (auto x : a) a1 += x != 0;
    a2 = a2 - n + 1;
    cout << min(a1, a2) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}