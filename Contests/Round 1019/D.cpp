// Codeforces Round 1019: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 1, r = n;
    vector<int> ans(n);
    int n1;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) n1 = i;
        mp[a[i]].push_back(i);
    }
    for (auto c : mp) {
        if (c.f == -1) continue;
        if (c.f % 2) {
            int R = r, L = r - c.s.size() + 1;
            r -= c.s.size();
            for (auto p : c.s) {
                if (p < n1)
                    ans[p] = R--;
                else
                    ans[p] = L++;
            }
        } else {
            int R = l + c.s.size() - 1, L = l;
            l += c.s.size();
            for (auto p : c.s) {
                if (p < n1)
                    ans[p] = L++;
                else
                    ans[p] = R--;
            }
        }
    }
    for (auto &x : ans)
        if (x == 0) x = l;
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
