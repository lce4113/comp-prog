// Codeforces Round 1014: Problem F

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
    int brks = 0, ans = 0;
    vector<int> cleans(n + 1);
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            brks++;
            vector<int> ds;
            for (int j = 1; j * j <= brks; j++) {
                if (brks % j) continue;
                ds.push_back(j);
                if (j * j != brks) ds.push_back(brks / j);
            }
            for (auto d : ds) {
                if (cleans[d] < d - 1) ans--;
            }
            ans++;
        } else {
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}