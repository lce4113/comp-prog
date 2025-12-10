// CSES Mathematics: Permutation Order

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 20;
vector<int> f(MAXN + 1, 1);

int kth(vector<bool> &rem, int k) {
    // cout << k << '\n';
    // for (auto x : rem) cout << x << ' ';
    // cout << '\n';
    for (int i = 0;; i++) {
        if (!rem[i]) continue;
        if (k == 0) {
            rem[i] = 0;
            return i + 1;
        }
        k--;
    }
}

int count(vector<bool> &rem, int k) {
    int ans = 0;
    for (int i = 0; i < k - 1; i++) ans += rem[i];
    return ans;
}

void solve() {
    int tp, n;
    cin >> tp >> n;
    if (tp == 1) {
        int k;
        cin >> k;
        k--;
        vector<int> ans;
        vector<bool> rem(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(kth(rem, k / f[i]));
            k %= f[i];
        }
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    } else {
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        int ans = 0;
        vector<bool> rem(n, 1);
        for (int i = 0; i < n; i++) {
            // for (auto x : rem) cout << x << ' ';
            // cout << '\n';
            // cout << a[i] << ' ' << count(rem, a[i]) << '\n';
            ans += count(rem, a[i]) * f[n - i - 1];
            rem[a[i] - 1] = 0;
        }
        cout << ans + 1 << '\n';
    }
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i;

    int t = 1;
    cin >> t;
    while (t--) solve();
}
