// Codeforces Round #968: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    vector<pair<int, char>> cs;
    for (auto x : mp) {
        // cout << x.f << ' ' << x.s << '\n';
        cs.push_back({x.s, x.f});
    }
    sort(cs.rbegin(), cs.rend());
    // for (auto x : cs) cout << x.f << ' ' << x.s << '\n';
    string ans = "";
    int end = cs.size();
    while (end > 0) {
        int nend = end;
        for (int i = 0; i < end; i++) {
            cs[i].f--;
            ans += cs[i].s;
            // cout << cs[i].f << ' ' << cs[i].s << '\n';
            if (cs[i].f == 0) nend--;
        }
        end = nend;
        // cout << end << '\n';
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}