// Codeforces Round 1004: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int q(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int n;
    cin >> n;
    return n;
}
void u(bool A) { cout << "! " << (A ? "A" : "B") << endl; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n + 1);
    for (auto &x : a) cin >> x;

    set<int> b;
    for (auto x : a) b.insert(x);

    for (int i = 1; i <= n; i++) {
        c[a[i - 1]] = i;
        if (!b.count(i)) {
            u(q(i, a[0]) == 0);
            return;
        }
    }

    int r1 = q(c[1], c[n]);
    int r2 = q(c[n], c[1]);

    if (r1 == 0 || r2 == 0 || r1 != r2) {
        u(1);
        return;
    }
    if (r1 < n - 1) {
        u(1);
        return;
    }
    u(0);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
