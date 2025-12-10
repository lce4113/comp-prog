// CSES Range Queries: Range Interval Queries

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
vector<int> a[2 * MAXN];

struct Tree {
    int n;
    void f(vector<int> &x, vector<int> &y, vector<int> &z) {
        z.assign(x.size() + y.size(), 0);
        merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
    }
    Tree(vector<int> &in) {
        n = in.size();
        for (int i = 0; i < n; i++) a[i + n] = {in[i]};
        for (int i = n - 1; i >= 1; i--) f(a[2 * i], a[2 * i + 1], a[i]);
    }
    int count(vector<int> &v, int L, int R) {
        return upper_bound(v.begin(), v.end(), R) -
               lower_bound(v.begin(), v.end(), L);
    }
    int q(int l, int r, int L, int R) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += count(a[l++], L, R);
            if (r % 2) ans += count(a[--r], L, R);
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    Tree seg(A);
    while (q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        l--;
        cout << seg.q(l, r, L, R) << '\n';
    }
}