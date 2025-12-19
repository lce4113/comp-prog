// Codeforces Global Round 31: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;

string bin(int n) {
    string res;
    while (n) {
        res += (n & 1) ? '1' : '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int solve() {
    vector<int> ans(k, n);
    ans[0] = ans[1] = 0;
    int N = n - (1ll << __lg(n));
    if (N == 0) {
        ans[1] = n;
    } else {
        ans[0] ^= ((1ll << (1 + __lg(N))) - 1) ^ N;
        ans[0] ^= 1ll << __lg(N);
        ans[1] ^= (1ll << __lg(N)) - 1;
        ans[1] ^= 1ll << __lg(n);
    }
    return reduce(ans.begin(), ans.end());
}

void check() {
    vector<int> ans(4, 0);
    for (int v1 = 0; v1 <= n; v1++) {
        for (int v2 = 0; v2 <= n; v2++) {
            for (int v3 = 0; v3 <= n; v3++) {
                int v4 = v1 ^ v2 ^ v3 ^ n;
                if (v4 > n) continue;
                if (v1 + v2 + v3 + v4 > reduce(ans.begin(), ans.end())) {
                    ans = {v1, v2, v3, v4};
                }
            }
        }
    }
    if (reduce(ans.begin(), ans.end()) != solve()) {
        cout << bin(n) << ' ' << k << '\n';
        cout << "ans: ";
        for (auto x : ans) cout << bin(x) << ' ';
        cout << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    k = 4;
    // n = 30;
    for (int i = 1; i <= 1e2; i++) {
        n = i;
        check();
    }

    // int t = 1;
    // cin >> t;
    // while (t--) solve();
}