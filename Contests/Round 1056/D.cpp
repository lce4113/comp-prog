// Codeforces Round 1056: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<int> p;

bool q(int a, int b) {
    cout << p[a] << ' ' << p[b] << endl;
    int n;
    cin >> n;
    return n == 1;
}

void solve() {
    int n;
    cin >> n;

    p.assign(n, 0);
    iota(p.begin(), p.end(), 1);

    // vector<pair<int, int>> ps;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         ps.push_back({i, j});
    //     }
    // }
    random_device rd;
    mt19937 g(rd());
    shuffle(p.begin(), p.end(), g);

    for (int j = 1; j < n; j++) {
        for (int i = 0; i + j < n; i++) {
            if (q(i, i + j)) {
                return;
            }
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // long double mxp = 0;
    // for (int n = 2; n <= 40; n++) {
    //     for (int a = 2; a <= n; a++) {
    //         if ((n * (n - 1) - a * (a - 1)) / 2 > n * n / a) {
    //             long double p = n * (n - 1) - a * (a - 1);
    //             p /= n * (n - 1);
    //             p = pow(p, n * n / a);
    //             cout << n << ' ' << a << ' ' << (n * (n - 1) - a * (a - 1)) /
    //             2
    //                  << ' ' << n * n / a << '\n';
    //             cout << "p: " << p << '\n';
    //             mxp = max(mxp, p);
    //         }
    //     }
    // }
    // cout << "maxp: " << mxp << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}