// Codeforces Round #969: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) cin >> p[i];

    vector<vector<int>> cs(n + 1);
    for (int i = 2; i <= n; i++) cs[p[i]].push_back(i);

    queue<int> q;
    vector<int> d(n + 1, -1);
    q.push(1);
    d[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto c : cs[x]) {
            q.push(c);
            d[c] = d[x] + 1;
        }
    }

    vector<int> paths(n + 1, -1);
    paths[1] = d[n];
    for (int i = 2; i <= n; i++) paths[i] = d[i - 1] - d[p[i]] + 1;

    vector<int> mchild(n + 1, -1);
    for (int i = n; i >= 1; i--) {
        mchild[i] = max(i, mchild[i]);
        for (auto c : cs[i]) mchild[i] = max(mchild[c], mchild[i]);
    }

    int unfill = n, ans = w * unfill;
    map<int, int> curr;
    int N = n - 1;
    while (N--) {
        int a, b;
        cin >> a >> b;

        curr[a] += b;
        curr[mchild[a] % n + 1] += b;
        ans += 2 * b;

        paths[a]--, paths[mchild[a] % n + 1]--;
        if (paths[a] == 0) {
            unfill--;
            ans -= w;
        }
        if (paths[mchild[a] % n + 1] == 0) {
            unfill--;
            ans -= w;
        }

        ans -= unfill * w;
        w -= b;
        ans += unfill * w;

        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
