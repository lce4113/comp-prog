// CSES Interactive Problems: Hidden Permutation

#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int q(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    string a;
    cin >> a;
    return a == "YES";
}

void sor(int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) / 2;
    sor(l, m);
    sor(m, r);
    vector<int> comb(r - l);
    merge(p.begin() + l, p.begin() + m, p.begin() + m, p.begin() + r,
          comb.begin(), [&](int x, int y) { return q(x + 1, y + 1); });
    for (int i = 0, j = l; j < r; i++, j++) p[j] = comb[i];
}

int32_t main() {
    int n;
    cin >> n;
    p.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
    sor(0, n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[p[i]] = i + 1;
    cout << "! ";
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}