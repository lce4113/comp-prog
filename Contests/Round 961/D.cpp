// Codeforces Round 961: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    string a;
    cin >> a;

    set<int> bms;
    map<int, int> mp;
    for (int i = 0; i < k - 1; i++) mp[a[i] - 'A']++;
    for (int i = k - 1; i < n; i++) {
        if (i > k - 1) mp[a[i - k] - 'A']--;
        mp[a[i] - 'A']++;
        // for (auto x : mp) cout << (char)('A' + x.f) << ' ' << x.s << '\n';
        int curr = 0;
        for (int j = 0; j < c; j++) {
            if (mp[j] > 0) curr += (1 << j);
        }
        // cout << curr << '\n';
        bms.insert(curr);
    }
    bms.insert(1 << (a.back() - 'A'));

    // for (auto x : bms) cout << x << ' ';
    // cout << '\n';

    vector<bool> bad(1 << c, false);
    set<int> vis;
    queue<int> Q;
    for (auto x : bms) {
        bad[x] = true;
        Q.push(x);
    }
    while (Q.size()) {
        int x = Q.front();
        Q.pop();
        // while (x) {
        //     cout << x % 2;
        //     x /= 2;
        // }
        // cout << '\n';
        // cout << x << '\n';
        for (int i = 0, X = x; i < c; i++, X /= 2) {
            // cout << X % 2;
            if (X % 2) continue;
            if (bad[x + (1 << i)]) continue;
            Q.push(x + (1 << i));
            bad[x + (1 << i)] = true;
        }
        // cout << '\n';
    }

    int ans = 1e9;
    for (int i = 0; i < (1 << c); i++) {
        if (bad[i]) continue;
        int x = i, cnt = c;
        while (x > 0) {
            // cout << x % 2;
            cnt -= x % 2, x /= 2;
        }
        // cout << '\n';
        ans = min(ans, cnt);
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}