// Educational Codeforces Round 185: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int M = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> lst(n, 1e9);
    while (m--) {
        int l, r;
        cin >> l >> r;
        lst[r - 1] = min(lst[r - 1], r - l + 1);
    }
    queue<int> Q;
    Q.push(2);
    int tot = 2;
    for (int i = 1; i < n; i++) {
        Q.push(tot);
        tot = (tot + tot) % M;
        while (Q.size() >= lst[i]) tot = (tot + M - Q.front()) % M, Q.pop();
    }
    cout << tot << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}