// Codeforces Round #983: Problem D

#include <bits/stdc++.h>
using namespace std;

bool q(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int n;
    cin >> n;
    return (n == 1);
}

void A(vector<int> a) {
    cout << "! " << a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        cout << ' ' << a[i];
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    int i = 2;
    vector<int> ps(1, 1), psn, ans(1, 0);
    while (i < n && q(i, 1)) {
        ps.push_back(i++), ans.push_back(0);
    }
    for (; i < n;) {
        // cout << i << '\n';
        // for (auto x : ps) cout << x << ' ';
        // cout << '\n';
        for (auto p : ps) {
            if (p == 1 || ps.size() == 1 || !q(i, p)) {
                psn.push_back(i);
                ans.push_back(p);
                if (++i >= n) break;
            }
        }
        ps = psn;
        psn.clear();
    }
    A(ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}