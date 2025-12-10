// Codeforces Pinely Round 5: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, X;
    cin >> n >> X;
    vector<int> a(n), ans;
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int sm = reduce(a.begin(), a.end());
    vector<int> p1, p2;
    for (int i = 0; i < sm / X; i++) {
        p1.push_back(a[i]);
    }
    for (int i = sm / X; i < n; i++) {
        p2.push_back(a[i]);
    }
    int c = 0, i = 0, j = 0;
    while (i < p1.size() && j < p2.size()) {
        if ((c + p1[i]) / X != c / X) {
            ans.push_back(p1[i]);
            c += p1[i];
            i++;
        } else {
            ans.push_back(p2[j]);
            c += p2[j];
            j++;
        }
    }
    while (i != p1.size()) ans.push_back(p1[i++]);
    while (j != p2.size()) ans.push_back(p2[j++]);
    cout << reduce(p1.begin(), p1.end()) << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}