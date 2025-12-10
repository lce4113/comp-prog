// NAC 2025: Problem K

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    a.insert(a.begin(), 0), n++;
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) {
            ans += a[i + 1] - a[i], ans++;
        }
    }
    cout << ans << '\n';
}