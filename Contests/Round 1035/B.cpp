// Codeforces Round 1035: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long double
#define f first
#define s second

void solve() {
    int n;
    int px, py, qx, qy;
    cin >> n >> px >> py >> qx >> qy;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int dx = px - qx, dy = py - qy;
    a.push_back(sqrtl(dx * dx + dy * dy));
    int sm = reduce(a.begin(), a.end());
    for (auto x : a) {
        if (sm - x < x) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}