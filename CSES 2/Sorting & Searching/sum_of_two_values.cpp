// CSES Sorting & Searching: Sum of Two Values

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f;
    for (int i = 0; i < n; i++) a[i].s = i + 1;
    sort(a.begin(), a.end());
    for (int i = 0, j = n - 1; i < j;) {
        if (a[i].f + a[j].f < k) {
            i++;
        } else if (a[i].f + a[j].f > k) {
            j--;
        } else {
            cout << a[i].s << ' ' << a[j].s << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}