// MITIT Spring 2025: Problem 3

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int os = 0;
    for (auto x : a) os += (x == 'O');
    if (n * (n * 2 + 1) % 2 != os % 2) {
        cout << "NO\n";
        return;
    }

    set<int> rem;
    for (int i = 1; i <= 2 * n; i++) rem.insert(i);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        int v1 = *rem.begin(), v2 = *(++rem.begin()), v3 = *(++(++rem.begin()));
        int s1 = v1 + v2;
        int s2 = v1 + v3;
        int par = a[i] == 'O' ? 1 : 0;
        if (s1 % 2 == par) {
            ans.push_back({v1, v2});
            rem.erase(v1), rem.erase(v2);
        } else {
            ans.push_back({v1, v3});
            rem.erase(v1), rem.erase(v3);
        }
    }
    ans.push_back({*rem.begin(), *(++rem.begin())});
    cout << "YES\n";
    for (auto x : ans) cout << x.f << ' ' << x.s << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
