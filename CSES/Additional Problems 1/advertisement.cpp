// CSES Additional Problems I: Advertisement

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n), L(n), R(n);
    for (auto &x : a) cin >> x;

    stack<pair<int, int>> Q;
    Q.push({-1, -1});
    for (int i = 0; i < n; i++) {
        while (Q.top().f >= a[i]) Q.pop();
        L[i] = Q.top().s;
        Q.push({a[i], i});
    }
    Q.push({-1, n});
    for (int i = n - 1; i >= 0; i--) {
        while (Q.top().f >= a[i]) Q.pop();
        R[i] = Q.top().s;
        Q.push({a[i], i});
    }
    // for (auto x : L) cout << x << ' ';
    // cout << '\n';
    // for (auto x : R) cout << x << ' ';
    // cout << '\n';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] * (R[i] - L[i] - 1));
    }
    cout << ans << '\n';
}