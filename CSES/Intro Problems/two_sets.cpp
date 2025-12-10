// CSES Introductory Problems: Two Sets

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int tot = n * (n + 1) / 2, sm = 0, i = n;
    if (tot % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    set<int> ans;
    for (; sm <= tot / 2; i--) {
        sm += i;
        ans.insert(i);
    }
    i++;
    sm -= i;
    ans.erase(i);
    if (tot / 2 - sm != 0) {
        ans.insert(tot / 2 - sm);
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    cout << n - ans.size() << '\n';
    for (int i = 1; i <= n; i++) {
        if (ans.count(i)) continue;
        cout << i << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}