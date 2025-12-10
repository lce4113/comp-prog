// Codeforces Educational Round 183: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (k == n) {
        string res(n, '-');
        cout << res << '\n';
        return;
    }
    int c2 = 0;
    for (auto x : a) c2 += x == '2';
    int l = 0, r = n - 1;
    string res(n, '+');
    for (int i = 0; i < k; i++) {
        if (a[i] == '2') continue;
        if (a[i] == '0') res[l++] = '-';
        if (a[i] == '1') res[r--] = '-';
    }
    while (c2--) {
        res[l++] = '?';
        res[r--] = '?';
    }
    cout << res << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}