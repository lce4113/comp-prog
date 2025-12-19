// Codeforces Round 1070: Problem C

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
    vector<int> os, es;
    for (auto x : a) {
        if (x % 2)
            os.push_back(x);
        else
            es.push_back(x);
    }
    sort(os.rbegin(), os.rend());
    sort(es.rbegin(), es.rend());
    vector<int> ans(n);
    if (es.size() == 0) {
        for (int i = 0; i < n; i += 2) {
            ans[i] = os[0];
        }
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    if (os.size() == 0) {
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    ans[0] = os[0];
    for (int i = 0; i < es.size(); i++) {
        ans[i + 1] = ans[i] + es[i];
    }
    if (os.size() < 3) {
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    ans[es.size() + 1] = ans[es.size()] - es.back();
    for (int i = es.size() + 2; i < n; i++) {
        ans[i] = ans[i - 2];
    }
    if (os.size() % 2 == 0) ans[n - 1] = 0;
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}