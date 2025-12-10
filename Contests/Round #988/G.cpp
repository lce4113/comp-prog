// Codeforces Round #988: Problem G

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MOD = 998244353;

const int MAXN = 1e6;
vector<int> prime(MAXN + 1, 1);

int n;
vector<int> a;

vector<int> pfac(int num) {
    vector<int> ans;
    while (num > 1) {
        int p = prime[num];
        // cout << num << ' ' << p << '\n';
        while (num % p == 0) num /= p;
        ans.push_back(p);
    }
    return ans;
}

// int check() {
//     vector<int> dp(n, 0);
//     dp[0] = 1;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (gcd(a[i], a[j]) != 1) dp[i] += dp[j];
//         }
//     }
//     // for (auto x : dp) cout << x << ' ';
//     // cout << '\n';
//     return dp[n - 1];
// }

void solve() {
    // int solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    map<int, int> mp;
    int ans;
    for (int x = 0; x < n; x++) {
        vector<int> p = pfac(a[x]);
        // cout << a[x] << ' ';
        // for (auto y : p) cout << y << ' ';
        // cout << '\n';
        int tot = 0;
        for (int i = 1; i < (1 << p.size()); i++) {
            int curr = 1, ps = 0;
            for (int b = i, j = 0; b; b /= 2, j++) {
                if (b % 2) curr *= p[j], ps++;
            }
            if (ps % 2) {
                tot = (tot + mp[curr]) % MOD;
            } else {
                tot = (tot - mp[curr] + MOD) % MOD;
            }
        }
        if (x == 0) tot++;
        ans = tot;
        for (int i = 1; i < (1 << p.size()); i++) {
            int curr = 1;
            for (int b = i, j = 0; b; b /= 2, j++) {
                if (b % 2) curr *= p[j];
            }
            mp[curr] = (mp[curr] + tot) % MOD;
        }
        // for (auto X : mp) cout << X.f << ' ' << X.s << '\n';
        // cout << '\n';
    }
    cout << ans << '\n';
    // return ans;
}

int32_t main() {
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i] != 1) continue;
        for (int c = i; c <= MAXN; c += i) {
            prime[c] = i;
        }
    }
    solve();

    // for (int i1 = 1; i1 <= 100; i1++) {
    //     for (int i2 = 1; i2 <= 100; i2++) {
    //         for (int i3 = 1; i3 <= 100; i3++) {
    //             n = 3;
    //             a = {i1, i2, i3};
    //             int ans1 = solve(), ans2 = check();
    //             cout << i1 << ' ' << i2 << ' ' << i3 << '\n';
    //             cout << ans1 << ' ' << ans2 << '\n';
    //             if (ans1 != ans2) {
    //                 cout << "ohno\n";
    //                 return 0;
    //             }
    //         }
    //     }
    // }
}