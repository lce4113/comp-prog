// Meta Hacker Cup 2025 Round 1: Problem B1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int N = 1e3;
vector<int> lp(N + 1), pr;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    // vector<int> db;
    // for (int i = 1; i*i <= b; i++) {
    //     if (b % i) continue;
    //     if (i*i!=b) db.push_back();
    // }
    // sort(db.begin(), db.end());
    // int lb = --upper_bound(db.begin());
    for (int i = 0; i < n; i++) cout << 1 << ' ';
    cout << b << ' ';
    for (int i = 0; i < n - 1; i++) cout << 1 << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    // for (int i = 2; i <= N; i++) {
    //     if (lp[i] == 0) {
    //         pr.push_back(i);
    //         lp[i] = i;
    //     }
    //     for (int j = 0; pr[j] * i <= N; j++) {
    //         lp[pr[j] * i] = pr[j];
    //         if (pr[j] == lp[i]) break;
    //     }
    // }

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}