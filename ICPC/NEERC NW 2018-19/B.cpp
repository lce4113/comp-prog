// NEERC NW 2018-19: Problem B

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
    if (n % 2) {
        int m = (n + 1) / 2;
        cout << m << '\n';
        vector<string> a(m, string(m, '.'));
        for (int i = 0; i < m; i++) {
            a[m - 1][i] = 'o';
        }
        for (int i = 0; i < m; i++) {
            a[i][0] = 'o';
        }
        for (auto x : a) cout << x << '\n';
    } else {
        int m = (n + 1) / 2;
        cout << m << '\n';
        vector<string> a(m, string(m, '.'));
        for (int i = 0; i < m; i++) {
            a[m - 1][i] = 'o';
        }
        for (int i = 0; i < m; i++) {
            a[i][0] = 'o';
        }
        a[m - 2][1] = 'o';
        for (auto x : a) cout << x << '\n';
    }
}