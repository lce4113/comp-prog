// ASC 1: Problem C

#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef ONLINE_JUDGE
    ifstream cin("grant.in");
    ofstream cout("grant.out");
#endif

    int n;
    cin >> n;
    vector<int> p(n), ans;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<bool> use(n, 0);
    for (int i = n - 1; i >= 1; i--) {
        if (use[p[i]] || use[i]) continue;
        use[i] = use[p[i]] = 1;
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() * 1000 << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}