// CSES Sorting & Searching: Sum of Three Values

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, sm;
    cin >> n >> sm;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    map<int, vector<pair<int, int>>> b;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = sm - a[i] - a[j];
            if (mp.count(c)) {
                int k = 0;
                while (k < mp[c].size() && (mp[c][k] == i || mp[c][k] == j))
                    k++;
                if (k == mp[c].size()) continue;
                cout << mp[c][k] + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}