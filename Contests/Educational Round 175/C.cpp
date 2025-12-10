// Codeforces Educational Round 175: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;
vector<int> cs;
string a;

bool ch(int m) {
    bool on = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'B' && cs[i] > m && !on) {
            on = true;
            ans++;
            if (ans > k) return false;
        }
        if (a[i] == 'R' && cs[i] > m && on) {
            on = false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> k;
    cin >> a;
    cs.assign(n, 0);
    for (auto &x : cs) cin >> x;

    int l = -1, r = 1e9, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if (ch(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}