#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    for (auto x : b) mp[x]--;
    for (auto x : mp) {
        if (x.s != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}