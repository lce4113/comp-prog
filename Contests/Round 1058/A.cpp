// Codeforces Round 1058: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

set<int> rem;

vector<int> rng(int l, int r) {
    vector<int> v;
    for (int i = l; i <= r; i++) {
        if (rem.count(i)) continue;
        v.push_back(i);
    }
    return v;
}

int q(vector<int> ask) {
    cout << "? ";
    cout << ask.size() << ' ';
    for (auto x : ask) cout << x + 1 << ' ';
    cout << endl;
    int y;
    cin >> y;
    return y;
}

void solve() {
    rem.clear();
    int n;
    cin >> n;
    vector<int> ans(2 * n, 1);
    for (int i = 0; i < 2 * n; i++) {
        int c = q(rng(0, i));
        if (c != 0) {
            ans[i] = c;
            rem.insert(i);
        }
    }
    vector<int> ask;
    for (int i = 0; i < 2 * n; i++) {
        if (rem.count(i)) ask.push_back(i);
    }
    for (int i = 0; i < 2 * n; i++) {
        if (rem.count(i)) continue;
        ask.push_back(i);
        int c = q(ask);
        ans[i] = c;
        ask.pop_back();
    }
    // for (int i = n; i >= 2; i--) {
    //     int l = 0, r = 2 * n - 1;
    //     while (r - l > 1) {
    //         int m = (l + r) / 2;
    //         // cout << l << ' ' << m << ' ' << r << '\n';
    //         if (q(rng(0, m)) == i) {
    //             r = m;
    //         } else {
    //             l = m;
    //         }
    //     }
    //     int R = r;
    //     // cout << "R: " << R << '\n';
    //     l = 0, r = R;
    //     while (r - l > 1) {
    //         int m = (l + r) / 2;
    //         if (q(rng(m, R)) == i) {
    //             l = m;
    //         } else {
    //             r = m;
    //         }
    //     }
    //     int L = l;
    //     ans[L] = i, ans[R] = i;
    //     rem.insert(L), rem.insert(R);
    // }
    cout << "! ";
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}