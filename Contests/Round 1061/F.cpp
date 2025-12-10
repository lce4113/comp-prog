// Codeforces Round 1061: Problem F

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
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[--a[i]] = i;
    while (1) {
        bool ok = 0;
        for (int j = n - 1; j >= 0; j--) {
            int c = a[j];
            if (c - 2 >= 0 && p[c] < p[c - 1] && p[c] < p[c - 2]) {
                a[p[c]] -= 2, a[p[c - 1]]++, a[p[c - 2]]++;
                swap(p[c], p[c - 1]), swap(p[c - 1], p[c - 2]);
                ok = 1;
                break;
            }
        }
        // for (auto x : a) cout << x + 1 << ' ';
        // cout << '\n';
        if (!ok) break;
    }
    for (auto x : a) cout << x + 1 << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}