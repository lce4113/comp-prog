// Codeforces Educational Round 176: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;
vector<int> a;

int ch() {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (a[i] + a[j] < n) continue;
            ans += a[i] + a[j] - n + 1;
            // cout << a[i] << ' ' << a[j] << '\n';
        }
    }
    return 2 * ans;
}

int solve() {
    sort(a.begin(), a.end());

    vector<int> pfs(k + 1, 0);
    for (int i = k - 1; i >= 0; i--) {
        pfs[i] = pfs[i + 1] + (n - 1 - a[i]);
    }

    // for (auto x : pfs) cout << x << ' ';
    // cout << '\n';

    int ans = 0;
    for (int i = 0; i < k - 1; i++) {
        int p = lower_bound(a.begin(), a.end(), n - a[i]) - a.begin();
        p = max(p, i + 1);
        // cout << "k: " << p << ' ' << k << ' ' << i << '\n';
        ans += a[i] * (k - p) - pfs[p];
    }
    // cout << 2 * ans << '\n';
    return 2 * ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    k = 5;
    for (int i1 = 1; i1 <= 10; i1++) {
        for (int i2 = 1; i2 <= 10; i2++) {
            for (int i3 = 1; i3 <= 10; i3++) {
                for (int i4 = 1; i4 <= 10; i4++) {
                    for (int i5 = 1; i5 <= 10; i5++) {
                        for (int in = 2; in <= 50; in++) {
                            n = in;
                            a = {i1, i2, i3, i4, i5};
                            // a = {1, 1, 1, 1};
                            for (auto x : a) cout << x << ' ';
                            cout << '\n';
                            int a1 = solve(), a2 = ch();
                            cout << a1 << ' ' << a2 << '\n';
                            if (a1 != a2) {
                                cout << "ohno\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    // int t = 1;
    // cin >> t;
    // while (t--) solve();
}