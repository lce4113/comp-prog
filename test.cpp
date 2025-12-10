#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

struct Node {
    int lo, hi, mid, madd = 0, val = -INF;
    Node *L, *R;
    Node(int _lo, int _hi) : lo(_lo), hi(_hi) {
        mid = (lo + hi) / 2;
        if (hi - lo == 1) return;
        L = new Node(lo, mid);
        R = new Node(mid, hi);
    }
    int q(int l, int r) {
        if (hi <= l || r <= lo) return -INF;
        if (l <= lo && hi <= r) return val;
        push();
        return max(L->q(l, r), R->q(l, r));
    }
    void add(int l, int r, int v) {
        if (hi <= l || r <= lo) return;
        if (l <= lo && hi <= r) {
            val += v, madd += v;
            return;
        }
        push();
        L->add(l, r, v), R->add(l, r, v);
        val = max(L->val, R->val);
    }
    void push() {
        if (madd == 0) return;
        L->add(lo, hi, madd), R->add(lo, hi, madd);
        madd = 0;
    }
    void u(int p, int v) {
        if (hi - lo == 1) {
            val = v;
            return;
        }
        push();
        if (p < mid)
            L->u(p, v);
        else
            R->u(p, v);
        val = max(L->val, R->val);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][1];
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        a[p - 1][0] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        a[p - 1][2] = i + 1;
    }
    sort(a.begin(), a.end());
    Node dp(0, n + 1);
    dp.u(0, 0);
    for (int i = 0; i < n; i++) {
        dp.u(a[i][2], dp.q(0, a[i][2]));
        dp.add(0, a[i][2], a[i][1]);
        // for (int i = 0; i <= n; i++) cout << dp.q(i, i + 1) << ' ';
        // cout << '\n';
    }
    cout << dp.q(0, n + 1) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
