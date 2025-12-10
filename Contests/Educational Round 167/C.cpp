// Codeforces Educational Round 167
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int ar = 0, br = 0, osp = 0, osm = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 1)
            osp++;
        else if (a[i] == -1 && b[i] == -1)
            osm++;
        else if (a[i] >= b[i])
            ar += a[i];
        else
            br += b[i];
    }

    // cout << ar << ' ' << br << ' ' << osp << ' ' << osm << '\n';

    for (int i = 0; i < osm; i++) {
        if (ar > br)
            ar--;
        else
            br--;
    }
    for (int i = 0; i < osp; i++) {
        if (ar < br)
            ar++;
        else
            br++;
    }

    cout << min(ar, br) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}