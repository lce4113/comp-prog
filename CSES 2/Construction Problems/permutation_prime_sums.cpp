// CSES Construction Problems: Permutation Prime Sums

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
vector<int> lp(MAXN + 1), pr;
int n;

bool isp(int n) { return lp[n] == n; }

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    if (isp(n + 1)) {
        for (int j = n; j >= 1; j--) cout << j << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        if (isp(1 + i) && isp(i + 1 + n)) {
            for (int j = i; j >= 1; j--) cout << j << ' ';
            for (int j = n; j >= i + 1; j--) cout << j << ' ';
            cout << '\n';
            return;
        }
    }
    for (int i = 2; i < n; i++) {
        if (isp(2 + i) && isp(i + 1 + n)) {
            cout << "1 ";
            for (int j = i; j >= 2; j--) cout << j << ' ';
            for (int j = n; j >= i + 1; j--) cout << j << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
    exit(0);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

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

    // for (int c = 1; c <= 1e3; c++) {
    //     n = c;
    // cout << "n: " << n << '\n';
    solve();
    // }
}
