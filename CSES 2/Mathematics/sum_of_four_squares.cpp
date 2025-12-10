// CSES Mathematics: Sum of Four Squares

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e7;
vector<pair<int, int>> two(MAXN + 1, {-1, -1});

void solve() {
    int n;
    cin >> n;
    for (int i = 0, j = n; i <= j; i++, j--) {
        // cout << i << ' ' << j << '\n';
        if (two[i].f != -1 && two[j].f != -1) {
            cout << two[i].f << ' ' << two[i].s << ' ' << two[j].f << ' '
                 << two[j].s << '\n';
            return;
        }
    }
}

int32_t main() {
    for (int i = 0; i * i <= MAXN; i++) {
        for (int j = 0; i * i + j * j <= MAXN; j++) {
            two[i * i + j * j] = {i, j};
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}