// CSES Geometry: All Manhattan Distances

#include <bits/stdc++.h>
using namespace std;

#define L __int128
#define x first
#define y second
using pt = pair<int, int>;

struct Tree {
    int n;
    vector<L> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, L val) {
        for (a[pos += n] += val; pos /= 2;) {
            a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
    }
    L q(int l, int r) {
        L res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res += a[l++];
            if (r % 2) res += a[--r];
        }
        return res;
    }
};

void print(L x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x) {
        s += '0' + x % 10;
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pt> P(n);
    for (auto &p : P) cin >> p.x >> p.y;
    sort(P.begin(), P.end());

    vector<int> nums;
    for (auto p : P) nums.push_back(p.x), nums.push_back(p.y);
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (auto &p : P) {
        p.x = lower_bound(nums.begin(), nums.end(), p.x) - nums.begin();
        p.y = lower_bound(nums.begin(), nums.end(), p.y) - nums.begin();
    }
    int N = nums.size();

    L ans = 0;
    Tree seg(N), cnt(N), seg2(N), cnt2(N);
    for (auto p : P) {
        L num = cnt.q(0, p.y);
        L tot = seg.q(0, p.y);
        // cout << p.x << ' ' << p.y << ' ' << num << ' ' << tot << '\n';
        num *= (nums[p.x] + nums[p.y]);
        ans += num - tot;
        seg.u(p.y, nums[p.x] + nums[p.y]);
        cnt.u(p.y, 1);
    }
    // cout << ans << '\n';
    for (auto p : P) {
        L num = cnt2.q(p.y, N);
        L tot = seg2.q(p.y, N);
        // cout << p.x << ' ' << p.y << ' ' << num << ' ' << tot << '\n';
        num *= (nums[p.x] - nums[p.y]);
        ans += num - tot;
        seg2.u(p.y, nums[p.x] - nums[p.y]);
        cnt2.u(p.y, 1);
    }
    print(ans);
}