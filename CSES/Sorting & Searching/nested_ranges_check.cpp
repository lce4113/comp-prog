// CSES Sorting & Searching: Nested Ranges Check

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int n;
    vector<int> a;
    int f(int x, int y) { return x + y; }
    Tree(int n) : n(n), a(2 * n) {}
    void u(int pos) {
        for (a[pos += n]++; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = 0, rb = 0;
        for (l += n, r += n; r > l; r /= 2, l /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (auto &x : a) cin >> x.f.f >> x.f.s;
    for (int i = 0; i < n; i++) a[i].s = i, a[i].f.s *= -1;

    int N = 0;
    vector<int> nums;
    for (auto x : a) nums.push_back(x.f.f), nums.push_back(-x.f.s);
    sort(nums.begin(), nums.end());
    map<int, int> mp;
    for (auto x : nums) mp[x] = N++;

    sort(a.begin(), a.end());

    Tree seg1(N), seg2(N);
    vector<int> a1(n, 0), a2(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        a1[a[i].s] += seg1.q(0, mp[-a[i].f.s] + 1);
        seg1.u(mp[-a[i].f.s]);
    }

    for (int i = 0; i < n; i++) {
        // cout << -a[i].f.s << '\n';
        // for (auto x : seg2.a) cout << x << ' ';
        // cout << '\n';
        a2[a[i].s] += seg2.q(mp[-a[i].f.s], N);
        seg2.u(mp[-a[i].f.s]);
    }

    for (auto x : a1) cout << x << ' ';
    cout << '\n';
    for (auto x : a2) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}