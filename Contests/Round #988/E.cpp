// Codeforces Round #988: Problem E

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

int val;

int q(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int ans;
    cin >> ans;
    val = ans;
    return ans;
}

void res(string ans) { cout << "! " << ans << endl; }

void solve() {
    int n;
    cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) ans += '1';

    int st = 1, i = 2;
    while (q(st, i) == 0) {
        if (i >= n) {
            res("IMPOSSIBLE");
            return;
        }
        i++;
    }
    int k = st;
    for (; k < i - val; k++) ans[k - 1] = '1';
    for (; k < i; k++) ans[k - 1] = '0';

    while (i < n) {
        st = i - 1;
        ans[i - 1] = '1';
        i++;
        while (i <= n && q(st, i) == i - st) {
            ans[i - 1] = '1';
            i++;
        }
        ans[i - 1] = '0';
        i++;
        while (i <= n && q(i - 1, i) == 0) {
            ans[i - 1] = '0';
            i++;
        }
    }
    res(ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}