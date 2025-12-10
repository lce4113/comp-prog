#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> a(n);
    for (auto &x : a) {
        cin >> x.s.f >> x.s.s;
        x.f = x.s.f + x.s.s;
    }
    sort(a.begin(), a.end());
    // sort(a.begin(), a.end(), []());
    // sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
    //     int c1 = a.f > b.f;
    //     int c2 = a.f > b.s;
    //     int c3 = a.s > b.f;
    //     int c4 = a.s > b.s;
    //     int sm = c1 + c2 + c3 + c4;
    //     if (sm == 3 || sm == 4) return false;
    //     return true;
    // });
    for (auto x : a) cout << x.s.f << ' ' << x.s.s << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}