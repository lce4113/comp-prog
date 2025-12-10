// Codeforces Round 1033: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    // cout << "n m: ";
    // cout << n << ' ' << m << '\n';
    if (m > n * (n + 1) / 2 || m < n) {
        cout << "-1\n";
        return;
    }
    int c = n;
    set<int> rem;
    for (int i = 1; i <= n; i++) rem.insert(i);
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        if (c + i - 1 > m) break;
        ans.push_back(i);
        rem.erase(i);
        c += i - 1;
    }
    // cout << "ans: ";
    // for (auto x : ans) cout << x << ' ';
    // cout << '\n';
    if (m - c + 1 != 1) {
        ans.push_back(m - c + 1);
        rem.erase(m - c + 1);
    }
    // cout << "ans: ";
    // for (auto x : ans) cout << x << ' ';
    // cout << '\n';
    if (ans.size() < n) {
        ans.push_back(1);
        rem.erase(1);
    }
    for (auto x : rem) ans.push_back(x);
    // cout << "ans: ";
    // for (auto x : ans) cout << x << ' ';
    // cout << '\n';
    cout << ans[0] << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}