// Codeforces Round 1061: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int B = 15;

bool q(int i, int x) {
    cout << "? " << i << ' ' << x << endl;
    int b;
    cin >> b;
    return b;
}

void solve() {
    int n;
    cin >> n;
    set<int> ind;
    for (int i = 1; i <= n - 1; i++) ind.insert(i);
    int ans = 0;
    for (int b = 0; (1 << b) <= n; b++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i % (1 << b) == ans && (i & (1 << b))) cnt++;
        }
        // cout << cnt << '\n';
        vector<int> one, zero;
        for (auto c : ind) {
            if (q(c, 1 << b))
                one.push_back(c);
            else
                zero.push_back(c);
        }
        if (one.size() < cnt) {
            for (auto x : zero) ind.erase(x);
            ans ^= 1 << b;
        } else {
            for (auto x : one) ind.erase(x);
        }
    }
    cout << "! " << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}