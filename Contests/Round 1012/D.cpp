// Codeforces Round 1012: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int MAXN = 1e5;

vector<int> lp(MAXN + 1), pr;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "2 1\n";
        return;
    }
    if (n == 3) {
        cout << "2 1 3\n";
        return;
    }
    if (n == 4) {
        cout << "2 1 3 4\n";
        return;
    }
    if (n == 5) {
        cout << "2 1 3 4 5\n";
        return;
    }
    // cout << n / 2 << '\n';
    int p = *(--upper_bound(pr.begin(), pr.end(), n / 2));
    cout << p << ' ';

    int i = p + 1;
    for (int j = p - 1; j >= 1; i++, j--) {
        cout << i << ' ' << j << ' ';
    }

    for (; i <= n; i++) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    // for (auto x : pr) cout << x << ' ';
    // cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}