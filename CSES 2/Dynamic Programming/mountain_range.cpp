// CSES Dynamic Programming: Mountain Range

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> L(n), R(n);
    stack<int> Q;
    Q.push(-1);
    for (int i = 0; i < n; i++) {
        while (Q.top() != -1 && a[Q.top()] <= a[i]) Q.pop();
        L[i] = Q.top();
        Q.push(i);
    }
    while (Q.size()) Q.pop();
    Q.push(-1);
    for (int i = n - 1; i >= 0; i--) {
        while (Q.top() != -1 && a[Q.top()] <= a[i]) Q.pop();
        R[i] = Q.top();
        Q.push(i);
    }

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) p.push_back({a[i], i});
    sort(p.rbegin(), p.rend());
    vector<int> dp(n);
    for (auto [_, i] : p) {
        dp[i] = max(L[i] == -1 ? 0 : dp[L[i]], R[i] == -1 ? 0 : dp[R[i]]) + 1;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}