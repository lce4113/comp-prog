// ASC 31: Problem K

#include <bits/stdc++.h>
using namespace std;

string a;
int n;

vector<string> make(vector<string> &L, vector<string> &R, char op) {
    int h1 = L.size(), w1 = L[0].size();
    int h2 = R.size(), w2 = R[0].size();
    int H = max(h1, h2) + 2, W = w1 + w2 + 5;
    vector<string> res(H, string(W, ' '));
    for (int x = 0; x < h1; x++) {
        for (int y = 0; y < w1; y++) {
            res[2 + x][y] = L[x][y];
        }
    }
    for (int x = 0; x < h2; x++) {
        for (int y = 0; y < w2; y++) {
            res[2 + x][w1 + 5 + y] = R[x][y];
        }
    }
    res[0][w1] = '-';
    res[0][w1 + 1] = '[';
    res[0][w1 + 2] = op;
    res[0][w1 + 3] = ']';
    res[0][w1 + 4] = '-';
    int pl = find(L[0].begin(), L[0].end(), '[') - L[0].begin();
    int pr = find(R[0].begin(), R[0].end(), '[') - R[0].begin();
    pl = (pl == (int)L[0].size() ? 0 : pl + 1);
    pr = (pr == (int)R[0].size() ? 0 : pr + 1);
    for (int x = pl; x <= w1; x++) {
        res[0][x] = '-';
    }
    for (int x = 0; x <= pr; x++) {
        res[0][w1 + 5 + x] = '-';
    }
    res[0][pl] = '.';
    res[0][w1 + 5 + pr] = '.';
    res[1][pl] = '|';
    res[1][w1 + 5 + pr] = '|';
    return res;
}

int fnd(vector<bool> &good, int l, int r, char op) {
    for (int i = r; i >= l; i--) {
        if (good[i] && a[i] == op) return i;
    }
    return -1;
}

vector<string> rec(int l, int r) {
    if (l == r) {
        return {string(1, a[l])};
    }
    vector<bool> good(n, 0);
    for (int i = l, c = 0; i <= r; i++) {
        c += a[i] == '(';
        good[i] = c == 0;
        c -= a[i] == ')';
    }
    int pl = fnd(good, l, r, '+');
    int mi = fnd(good, l, r, '-');
    int p = max(pl, mi);
    if (p != -1) {
        auto L = rec(l, p - 1);
        auto R = rec(p + 1, r);
        return make(L, R, a[p]);
    }
    int ti = fnd(good, l, r, '*');
    int di = fnd(good, l, r, '/');
    p = max(ti, di);
    if (p != -1) {
        auto L = rec(l, p - 1);
        auto R = rec(p + 1, r);
        return make(L, R, a[p]);
    }
    p = -1;
    for (int i = l; i <= r; i++) {
        if (a[i] == '^' && good[i]) {
            p = i;
            break;
        }
    }
    if (p != -1) {
        auto L = rec(l, p - 1);
        auto R = rec(p + 1, r);
        return make(L, R, '^');
    }
    return rec(l + 1, r - 1);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef ONLINE_JUDGE
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
#endif

    cin >> a;
    n = a.size();
    auto ans = rec(0, n - 1);
    for (auto x : ans) cout << x << '\n';
}