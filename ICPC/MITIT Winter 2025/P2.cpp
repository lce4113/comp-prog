// MITIT Adv Round 1: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int dec = -1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) dec = i;
    }
    if (!dec) {
        if (k <= 1) {
            cout << "YES\n1\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    vector<int> v1, v2;
    for (int i = 0; i < dec; i++) v1.push_back(a[i]);
    for (int i = dec; i < n; i++) v2.push_back(a[i]);

    int lg = -1;
    for (int i = n - k; i < dec; i++) {
        int d = v2.end() - lower_bound(v2.begin(), v2.end(), v1[i]);
        lg = max(lg, d + 1 + (i - k + dec));
    }
    cout << lg << '\n';
    if (lg <= (k + 1) / 2 && lg != -1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}