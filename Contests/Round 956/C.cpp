// Codeforces Round 956: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<int> test(vector<int> pa, vector<int> pb, vector<int> pc, int mn) {
    int n = pa.size();
    int ci = 0;
    while (ci < n && pa[ci] - pa[0] < mn) {
        // cout << pa[ci] - pa[0] << ' ';
        ci++;
    }
    if (ci >= n) return {-1};
    int i1 = ci;
    // cout << i1 << '\n';
    while (ci < n && pb[ci] - pb[i1] < mn) ci++;
    if (ci >= n) return {-1};
    int i2 = ci;
    // cout << i2 << '\n';
    while (ci < n && pc[ci] - pc[i2] < mn) ci++;
    if (ci >= n) return {-1};
    return {i1, i2};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
    vector<int> pa(1, 0), pb(1, 0), pc(1, 0);
    for (auto x : a) pa.push_back(pa.back() + x);
    for (auto x : b) pb.push_back(pb.back() + x);
    for (auto x : c) pc.push_back(pc.back() + x);

    int mn = ceil((long double)pa.back() / 3);

    // vector<int> arr = test(pa, pb, pc, mn);
    // for (auto x : arr) cout << x << ' ';
    // cout << '\n';

    vector<vector<int>> arr = {test(pa, pb, pc, mn), test(pa, pc, pb, mn),
                               test(pb, pa, pc, mn), test(pb, pc, pa, mn),
                               test(pc, pa, pb, mn), test(pc, pb, pa, mn)};

    int neg = true;
    for (auto ans : arr) {
        if (ans[0] != -1) neg = false;
    }
    if (neg) {
        cout << "-1\n";
        return;
    }

    vector<int> ans = arr[0];
    if (ans[0] != -1) {
        cout << 1 << ' ' << ans[0] << ' ';
        cout << ans[0] + 1 << ' ' << ans[1] << ' ';
        cout << ans[1] + 1 << ' ' << n << ' ';
        cout << '\n';
        return;
    }
    ans = arr[1];
    if (ans[0] != -1) {
        cout << 1 << ' ' << ans[0] << ' ';
        cout << ans[1] + 1 << ' ' << n << ' ';
        cout << ans[0] + 1 << ' ' << ans[1] << ' ';
        cout << '\n';
        return;
    }
    ans = arr[2];
    if (ans[0] != -1) {
        cout << ans[0] + 1 << ' ' << ans[1] << ' ';
        cout << 1 << ' ' << ans[0] << ' ';
        cout << ans[1] + 1 << ' ' << n << ' ';
        cout << '\n';
        return;
    }
    ans = arr[3];
    if (ans[0] != -1) {
        cout << ans[1] + 1 << ' ' << n << ' ';
        cout << 1 << ' ' << ans[0] << ' ';
        cout << ans[0] + 1 << ' ' << ans[1] << ' ';
        cout << '\n';
        return;
    }
    ans = arr[4];
    if (ans[0] != -1) {
        cout << ans[0] + 1 << ' ' << ans[1] << ' ';
        cout << ans[1] + 1 << ' ' << n << ' ';
        cout << 1 << ' ' << ans[0] << ' ';
        cout << '\n';
        return;
    }
    ans = arr[5];
    if (ans[0] != -1) {
        cout << ans[1] + 1 << ' ' << n << ' ';
        cout << ans[0] + 1 << ' ' << ans[1] << ' ';
        cout << 1 << ' ' << ans[0] << ' ';
        cout << '\n';
        return;
    }

    // for (auto x : arr) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}