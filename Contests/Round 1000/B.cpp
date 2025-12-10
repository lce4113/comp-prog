// Codeforces Round 1000: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), R, L;
    for (auto &x : a) cin >> x;

    for (int i = l - 1; i < n; i++) R.push_back(a[i]);
    for (int i = 0; i <= r - 1; i++) L.push_back(a[i]);
    sort(R.begin(), R.end());
    sort(L.begin(), L.end());

    int sm1 = 0, sm2 = 0;
    for (int i = 0; i < r - l + 1; i++) sm1 += L[i];
    for (int i = 0; i < r - l + 1; i++) sm2 += R[i];

    cout << min(sm1, sm2) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}