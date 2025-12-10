#include <bits/stdc++.h>
using namespace std;

int bin(vector<bool> a) {
    int res = 0, e = 1, n = a.size();
    for (int i = 0; i < n; i++, e *= 2) res += e * a[i];
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    if (n == 1 || m == 1) {
        cout << "No\n";
        return;
    }
    vector<vector<bool>> B(m, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[j][i] = a[i][j] == '1';
        }
    }
    vector<int> b;
    for (int i = 0; i < m; i++) {
        int c = bin(B[i]);
        b.push_back(c);
    }
    vector<int> sos(1 << n);
    vector<int> c(1 << n, -1);
    for (int i = 0; i < m; i++) {
        if (b[i] == 0) continue;
        sos[b[i]]++;
        c[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if ((1 << i) & j) continue;
            sos[j] += sos[j ^ (1 << i)];
        }
    }
    int os = (1 << n) - 1;
    int lst1 = -1, lst0 = -1;
    int overlap = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] == 0) continue;
        int comp = os ^ b[i];
        if (comp == 0) lst0 = c[b[i]];
        if (__builtin_popcount(b[i]) == 1) lst1 = c[b[i]];
        overlap += sos[comp];
        if (comp == 0) overlap--;
    }

    if (overlap != 2) {
        cout << "No\n";
        return;
    }

    pair<int, int> ans = {-1, -1};
    for (int i = 1; i < (1 << n) - 1; i++) {
        if (c[i] != -1 && c[os ^ i] != -1) ans = {c[i], c[os ^ i]};
    }

    if (ans.first != -1) {
        cout << "Yes\n";
        if (ans.first > ans.second) swap(ans.first, ans.second);
        cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
        return;
    }

    if (lst0 != -1 && lst1 != -1) {
        cout << "Yes\n";
        if (lst0 > lst1) swap(lst0, lst1);
        cout << lst0 + 1 << ' ' << lst1 + 1 << '\n';
        return;
    }

    cout << "No\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}