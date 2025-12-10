#include <algorithm>
#include <cassert>
#include <cstdint>
#include <climits>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

// CHT code from KACTL
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<pll>> occ(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
            occ[a[i][j]].emplace_back(i, j);
        }
    }

    constexpr ll INF = 1e18;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));

    for (auto& p : occ[0]) {
        dp[p.first][p.second] = 0;
    }

    for (int i = 1; i < k; ++i) {
        LineContainer by_x, by_y;
        for (auto& p : occ[i - 1]) {
            ll x, y;
            tie(x, y) = p;
            // (xi - xj)^2 + dp
            // xi^2 - 2 xi xj + xj^2 + dp
            // LC does max, so negate to get min
            by_x.add(2 * x, -x * x - dp[x][y]);
            by_y.add(2 * y, -y * y - dp[x][y]);
        }

        for (auto& q : occ[i]) {
            int x, y;
            tie(x, y) = q;
            if (!by_x.empty()) {
                dp[x][y] = min(dp[x][y], x * x - by_x.query(x));
            }
            if (!by_y.empty()) {
                dp[x][y] = min(dp[x][y], y * y - by_y.query(y));
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << dp[i][j] << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
    */

    ll ans = INF;
    for (auto& p : occ[k - 1]) {
        ans = min(ans, dp[p.first][p.second]);
    }

    cout << (ans == INF ? -1LL : ans) << '\n';

    return 0;
}
