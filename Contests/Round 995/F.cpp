// Codeforces Round 995: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> rng;
    rng.push_back({m, m});
    while (q--) {
        int x;
        cin >> x;
        bool rd = false;
        for (int i = 0; i < (int)rng.size(); i++) {
            if (x < rng[i].f && rng[i].f > 1) {
                if (i > 0 && rng[i - 1].s == rng[i].f - 1) continue;
                if (i == rng.size() - 1 && rd) continue;
                rng[i].f--;
            } else if (x > rng[i].s && rng[i].s < n) {
                if (i < rng.size() - 1 && rng[i + 1].f == rng[i].s + 1)
                    continue;
                rng[i].s++;
            } else {
                if (rng[i].f == rng[i].s && rng[i].f != 1 && rng[i].s != n)
                    rng.erase(rng.begin() + i);
                if (rng[0].f != 1) rng.insert(rng.begin(), {1, 1});
                if (rng.back().s != n) rd = true, rng.push_back({n, n});
            }
        }
        // for (auto y : rng) cout << y.f << ' ' << y.s << '\n';
        int ans = 0;
        for (int i = 0; i < (int)rng.size(); i++) {
            ans += rng[i].s - rng[i].f + 1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}