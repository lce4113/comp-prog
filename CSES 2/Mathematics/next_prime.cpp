// CSES Mathematics: Next Prime

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 1000;
vector<int> lp(MAXN + 1), pr;

bool is_prime(int n) {
    if (n == 1) return 0;
    for (int i = 0; pr[i] * pr[i] <= n; i++) {
        if (n % pr[i] == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    n++;
    if (n > 2 && n % 2 == 0) n++;
    while (!is_prime(n)) n += 2;
    cout << n << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; i++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}