// NWERC 2024: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int B = 20;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> nxt(n);
    vector<vector<int>> prev(n);
    stack<pair<int, int>> Q;
    Q.push({INF, n});
    for (int i = n - 1; i >= 0; i--) {
        while (Q.top().first <= a[i]) Q.pop();
        jump[0][i] = Q.top().second;
        Q.push({a[i], i});
    }

    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < n; j++) {
            jump[i][j] = jump[i - 1][j] == n ? n : jump[i - 1][jump[i - 1][j]];
        }
    }

    vector<int> ls(n);
    while (q--) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            int l, v;
            cin >> l >> v;
            l--;
            while (v && l < n) {
                int val = min(v, a[l]);
                ls[l] += val;
                a[l] -= val;
                v -= val;
                for (int i = B; i >= 0; i--) {
                    if (jump[i][l] != n && a[jump[i][l]] == 0) l = jump[i][l];
                }
                l = jump[0][l];
            }
        } else {
            int l;
            cin >> l;
            l--;
            cout << ls[l] << '\n';
        }
    }
}