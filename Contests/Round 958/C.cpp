// Codeforces Round 958: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define f first
#define s second

void solve() {
    int n;
    cin >> n;

    vector<int> cs;
    int c = 1;
    while (n > 0) {
        if (n % 2) cs.push_back(c);
        n /= 2, c *= 2;
    }
    reverse(cs.begin(), cs.end());

    // for (auto x : cs) cout << x << ' ';
    // cout << '\n';

    vector<int> ans;
    int sz = cs.size();
    for (int os = sz > 1 ? 0 : 1; os <= sz; os++) {
        int x = 0;
        for (int i = 0; i < sz; i++) {
            if (i < os) x += cs[i];
            if (i > os && (i - os) % 2) x += cs[i];
        }
        ans.push_back(x);
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}