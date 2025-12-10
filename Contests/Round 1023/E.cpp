// Codeforces Round 1023: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e5;

vector<int> tri(MAXN + 1);

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> nums;
    while (k) {
        auto it = --upper_bound(tri.begin(), tri.end(), k);
        k -= *it;
        int p = it - tri.begin();
        nums.push_back(p);
    }

    for (auto x : nums) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) tri[i] = i * (i - 1) / 2;
    // for (int i = 2; i < 10; i++) cout << tri[i] << ' ';
    // cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}