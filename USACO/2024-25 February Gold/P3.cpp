// USACO 2025 February Gold
// Problem 3. "Friendship Editing"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n;
vector<set<int>> adj;
int m;

int nbs(int x) {
    int ans = 0;
    while (x) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

int ch(int num) {
    vector<int> c;
    for (int i = 0; i < n; i++) {
        c.push_back(num % 2);
        num /= 2;
    }
    // for (auto x : nums) cout << x << ' ';
    // cout << '\n';
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (c[i])
            a.push_back(i);
        else
            b.push_back(i);
    }

    // for (auto x : a) cout << x << ' ';
    // cout << ": ";
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';

    int N = a.size(), M = b.size(), ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += adj[a[i]].count(b[j]);
        }
    }

    return (N * M - ans + (m - ans));
}

void solve() {
    cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    // for (auto x : adj) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    vector<int> nums;
    for (int i = 0; i < n; i++) nums.push_back(i);

    int ans = 1e18;
    for (int i = 0; i < (1 << n); i++) {
        ans = min(ans, ch(i));
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
