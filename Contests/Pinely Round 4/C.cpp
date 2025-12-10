// Codeforces Pinely Round 4: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (auto x : a) {
        if (x % 2 != a[0] % 2) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> ans;
    for (int i = 0; i < 30; i++) {
        ans.push_back(1 << i);
    }
    reverse(ans.begin(), ans.end());
    if (a[0] % 2 == 0) ans.push_back(1);
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}