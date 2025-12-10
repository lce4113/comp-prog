#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> P(n), V(n);
    for (auto &x : V) cin >> x;
    for (auto x : V) P[x - 1]++;
    int mxi = 0, mx = P[0];
    for (int i = 1; i < n; i++) {
        if (P[i] > mx) mxi = i, mx = P[i];
    }
    set<pair<int, int>> inc, dec;
    for (int i = 0; i <= mxi; i++) {
        if (P[i] == 0) continue;
        if (inc.empty() || P[i] > inc.back().f) inc.insert({P[i], i});
    }
    for (int i = n - 1; i > mxi; i--) {
        if (P[i] == 0) continue;
        if (dec.empty() || P[i] < dec.back().f) dec.insert({P[i], i});
    }

    // for (auto x : inc) cout << x.f << ' ' << x.s << '\n';
    // for (auto x : dec) cout << x.f << ' ' << x.s << '\n';

    int N = inc.size();
    set<int> a;
    int c = dec.size() - 1;
    for (int i = 0; i < N; i++) {
        a.insert(dec.lower_bound(mx - inc[i]));
    }

    for (auto x : b) cout << x << ' ';
    cout << '\n';

    while (q--) {
        int p, v;
        cin >> p >> v;
        p--;

        // decrement V[p]
        if (V[p] == mxi) {

        } else if (V[p] < mxi) {

        } else {
        }

        // increment v
        if (v == mxi) {

        } else if (v < mxi) {

        } else {
        }

        V[p] = v;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}