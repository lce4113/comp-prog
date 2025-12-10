// Codeforces Round 1014: Problem D

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
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    if (n == mp['L'] || n == mp['I'] || n == mp['T']) {
        cout << "-1\n";
        return;
    }
    int mn = min(min(mp['L'], mp['I']), mp['T']);
    int ld = mp['L'] - mn;
    int id = mp['I'] - mn;
    int td = mp['T'] - mn;
    vector<int> ans;
    for (int i = 0, c = 0; i < n - 1; i++, c++) {
        if (a[i] == a[i + 1]) continue;
        if (a[i] == 'L' && ld > 0) {
            for (int j = 0; j < 2 * ld; j++) ans.push_back(c);
            c += 2 * ld, ld = 0;
        }
        if (a[i + 1] == 'L' && ld > 0) {
            for (int j = 0; j < 2 * ld; j++, c++) ans.push_back(c);
            ld = 0;
        }
        if (a[i] == 'I' && id > 0) {
            for (int j = 0; j < 2 * id; j++) ans.push_back(c);
            c += 2 * id, id = 0;
        }
        if (a[i + 1] == 'I' && id > 0) {
            for (int j = 0; j < 2 * id; j++, c++) ans.push_back(c);
            id = 0;
        }
        if (a[i] == 'T' && td > 0) {
            for (int j = 0; j < 2 * td; j++) ans.push_back(c);
            c += 2 * td, td = 0;
        }
        if (a[i + 1] == 'T' && td > 0) {
            for (int j = 0; j < 2 * td; j++, c++) ans.push_back(c);
            td = 0;
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x + 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}