// Codeforces Round 1056: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 676767677;
int n;

bool test(string &a1, vector<int> &a) {
    vector<int> c(n, 1);
    for (int i = 0, l = 0; i < n; i++) {
        c[i] += l;
        l += a1[i] == 'L';
    }
    for (int i = n - 1, r = 0; i >= 0; i--) {
        c[i] += r;
        r += a1[i] == 'R';
    }
    // for (auto x : c) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n; i++) {
        if (a[i] != c[i]) return 0;
    }
    return 1;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    // for (int i = 0; i < n - 1; i++) {
    //     if (abs(a[i] - a[i + 1]) > 1) {
    //         cout << "0\n";
    //         return;
    //     }
    // }
    // int ans = 1;
    // for (int i = 0; i < n; i++) {
    //     if ((i - 1 < 0 || a[i] == a[i - 1]) && (i + 1 >= n || a[i] == a[i +
    //     1]))
    //         ans *= 2, ans %= MOD;
    // }
    // cout << ans << '\n';

    string a1, a2;
    a1[0] = 0, a2[0] = 1;
    a1 += 'R', a2 += 'L';
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            a1 += a1.back() == 'R' ? 'L' : 'R';
            a2 += a2.back() == 'R' ? 'L' : 'R';
        } else if (a[i] < a[i - 1]) {
            a1 += 'R';
            a2 += 'R';
        } else {
            a1 += 'L';
            a2 += 'L';
        }
    }
    // cout << a1 << ' ' << a2 << '\n';
    cout << test(a1, a) + test(a2, a) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}