#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

int n;
vector<int> a, b;

bool neq(vector<int> &x, vector<int> &y) {
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) return 1;
    }
    return 0;
}

long long binexp(long long a, long long b, long long m = MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
vector<int> solve() {
    vector<int> mxa(n), mxb(n);
    mxa[0] = 0;
    for (int i = 1; i < n; i++) {
        mxa[i] = (a[i] > a[mxa[i - 1]] ? i : mxa[i - 1]);
    }
    mxb[0] = 0;
    for (int i = 1; i < n; i++) {
        mxb[i] = (b[i] > b[mxb[i - 1]] ? i : mxb[i - 1]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int sma = (binexp(2, a[mxa[i]]) + binexp(2, b[i - mxa[i]])) % MOD;
        int smb = (binexp(2, b[mxb[i]]) + binexp(2, a[i - mxb[i]])) % MOD;
        ans[i] = max(sma, smb);
    }
    return ans;
}
vector<int> ch() {
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            ans[i] = max(ans[i], binexp(2, b[i - j]) + binexp(2, a[j]));
        }
    }
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    n = 100;
    a.assign(n, 0), b.assign(n, 0);
    for (int i = 0; i < n; i++) a[i] = i, b[i] = i;
    do {
        do {
            auto a1 = ch(), a2 = solve();
            if (neq(a1, a2)) {
                cout << "ohno\n";
                for (auto x : a1) cout << x << ' ';
                cout << '\n';
                for (auto x : a2) cout << x << ' ';
                cout << '\n';
                cout << '\n';
                for (auto x : a) cout << x << ' ';
                cout << '\n';
                for (auto x : b) cout << x << ' ';
                cout << '\n';
                return 0;
            }
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

    int t = 1;
    cin >> t;
    while (t--) solve();
}