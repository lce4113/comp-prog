// Codeforces Round 1011: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    priority_queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        q.push(a[i]);
        if ((n - i) % (k + 1) == 0) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}