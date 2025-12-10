// Codeforces Round 999: Problem B

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
    sort(a.begin(), a.end());

    int k = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) k = i;
    }
    if (k == -1) {
        cout << "-1\n";
        return;
    }

    int x = a[k];
    a.erase(a.begin() + k);
    a.erase(a.begin() + k - 1);
    for (int i = 0; i < n - 3; i++) {
        if (a[i + 1] < a[i] + 2 * x) {
            cout << a[i] << ' ' << a[i + 1] << ' ' << x << ' ' << x << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}