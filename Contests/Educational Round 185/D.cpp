// Educational Codeforces Round 185: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    vector<int> bad;
    int cq = 0;
    for (auto x : a) cq += x == '?';
    for (int i = 0; i < n; i++) {
        int st = i;
        while (i < n && a[i] == '?') i++;
        if (i - st != 0 && (i == n || a[i] == 'I')) bad.push_back(i - st);
    }
    cout << "bad: ";
    for (auto x : bad) cout << x << ' ';
    cout << '\n';
    vector<int> pfs(1, 0);
    for (auto x : bad) pfs.push_back(pfs.back() + x);
    while (q--) {
        int cx, cv, ci;
        cin >> cx >> cv >> ci;
        ci = min(ci, cq);
        cv = min(cv, cq - cx);
        ci = min(ci, cq - cv - cx);
        int bc = lower_bound(pfs.begin(), pfs.end(), cx + cv + ci) -
                 lower_bound(pfs.begin(), pfs.end(), cx + cv);
        int ans = cx * 10 + cv * 5 + ci - 2 * bc;
        cout << "cs: " << cx << ' ' << cv << ' ' << ci << '\n';
        cout << ans << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}