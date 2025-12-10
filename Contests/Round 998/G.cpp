// Codeforces Round 998: Problem G

#include <bits/stdc++.h>
using namespace std;

#define F0R(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define print pair<int, int>
#define vp vector<print>
#define ALL(x) (x).begin(), (x).end()

#define int long long
#define f first
#define s second

// int n;
// vp pairs;

// bool ch() {
//     sort(ALL(pairs), [](print a, print b) {
//         return min(a.first, a.second) < min(b.first, b.second);
//     });

//     vector<vector<int>> dp(4, vector<int>(n, 0));
//     dp[0][0] = 1;
//     dp[3][0] = 1;
//     FOR(i, 1, n) {
//         if (pairs[i - 1].first < pairs[i].first and
//             pairs[i - 1].second < pairs[i].second) {
//             dp[0][i] |= dp[0][i - 1];
//             dp[1][i] |= dp[1][i - 1];
//             dp[2][i] |= dp[3][i - 1];
//             dp[3][i] |= dp[2][i - 1];
//         }
//         if (pairs[i - 1].first < pairs[i].second and
//             pairs[i - 1].second < pairs[i].first) {
//             dp[0][i] |= dp[2][i - 1];
//             dp[1][i] |= dp[3][i - 1];
//             dp[2][i] |= dp[1][i - 1];
//             dp[3][i] |= dp[0][i - 1];
//         }
//     }
//     return (dp[0][n - 1] | dp[2][n - 1]);
// }

// bool solve() {
//     vector<int> a(n), b(n);
//     for (int i = 0; i < n; i++) a[i] = pairs[i].f;
//     for (int i = 0; i < n; i++) b[i] = pairs[i].s;
//     vector<pair<int, int>> ps;
//     int sw = 0, adj = 0;
//     for (int i = 0; i < n; i++) {
//         adj += (abs(a[i] - b[i]) == 1);
//         if (a[i] > b[i]) {
//             sw++;
//             swap(a[i], b[i]);
//         }
//         ps.push_back({a[i], b[i]});
//     }
//     sort(ps.begin(), ps.end());

//     for (int i = 1; i < n; i++) {
//         if (ps[i - 1].s > ps[i].s) {
//             return false;
//         }
//     }

//     if (adj == 0 && sw % 2 && n % 2 == 0) {
//         return false;
//     }

//     return true;
// }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    // for (int i = 0; i < n; i++) pairs.push_back({a[i], b[i]});
    // cout << ch() << '\n';

    vector<pair<int, int>> ps;
    int sw = 0, adj = 0;
    for (int i = 0; i < n; i++) {
        adj += (abs(a[i] - b[i]) == 1);
        if (a[i] > b[i]) {
            sw++;
            swap(a[i], b[i]);
        }
        ps.push_back({a[i], b[i]});
    }
    sort(ps.begin(), ps.end());

    bool pref = false;
    for (int i = 1; i < n; i++) {
        if (ps[i - 1].s > ps[i].s) {
            cout << "NO\n";
            return;
        }
        if (i % 2 == 1 && ps[i - 1].f < ps[i].s && ps[i - 1].s < ps[i].f)
            pref = true;
    }

    if (adj == 0 && sw % 2 && n % 2 == 0 && !pref) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();

    // n = 4;
    // int nums[2 * n];
    // for (int i = 1; i <= 2 * n; i++) nums[i - 1] = i;
    // do {
    //     pairs.clear();
    //     for (int i = 0; i < n; i++) {
    //         pairs.push_back({nums[2 * i], nums[2 * i + 1]});
    //     }
    //     // for (auto x : nums) cout << x << " ";
    //     // cout << '\n';
    //     // for (auto x : pairs) cout << x.f << ' ' << x.s << ", ";
    //     // cout << '\n';
    //     int a1 = solve();
    //     int a2 = ch();
    //     cout << a1 << ' ' << a2 << '\n';
    //     for (int i = 0; i < n; i++) cout << pairs[i].f << ' ';
    //     cout << '\n';
    //     for (int i = 0; i < n; i++) cout << pairs[i].s << ' ';
    //     cout << '\n';
    //     // cout << '\n';
    //     if (a1 != a2) {
    //         cout << "ohno\n";
    //         return 0;
    //     }
    // } while (next_permutation(nums, nums + 2 * n));
}