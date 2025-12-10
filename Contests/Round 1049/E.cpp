// Codeforces Round 1049: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int n, m, k;
vector<int> a;
vector<vector<int>> A, B;

int calca(int b, int l);
int calcb(int b, int l);
int calca(int b, int l) {
    if (l == 1) return b + 1;
    if (A[b][l]) return A[b][l];
    int ans = -1;
    for (auto i : a) {
        if (i >= l) continue;
        int rem = b % (1 << i);
        int c = ((b >> (i + 1)) << i) + rem;
        ans = max(ans, calcb(c, l - 1));
    }
    A[b][l] = ans;
    return ans;
}
int calcb(int b, int l) {
    if (l == 1) return b + 1;
    if (B[b][l]) return B[b][l];
    int ans = 3;
    for (auto i : a) {
        if (i >= l) continue;
        int rem = b % (1 << i);
        int c = ((b >> (i + 1)) << i) + rem;
        ans = min(ans, calca(c, l - 1));
    }
    B[b][l] = ans;
    return ans;
}

void solve() {
    cin >> n >> m >> k;
    a.assign(k, 0);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    if (m == 1) {
        cout << 1 << '\n';
        return;
    }
    A.assign(1 << n, vector<int>(n + 1, 0));
    B.assign(1 << n, vector<int>(n + 1, 0));
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans += calca(i, n);
        ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}