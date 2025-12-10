// Codeforces Round 953: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (auto &x : a) cin >> x;
    int l;
    cin >> l;
    sort(a.rbegin(), a.rend());
    cout << a[0] + l << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}