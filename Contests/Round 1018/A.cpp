// Codeforces Round 1018: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int mn = 0, l = -1, r = 1;
    vector<int> ans(1, 0);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == '<') ans.push_back(l--);
        if (a[i] == '>') ans.push_back(r++);
        mn = min(mn, ans.back());
    }
    for (auto &x : ans) cout << x - mn + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
