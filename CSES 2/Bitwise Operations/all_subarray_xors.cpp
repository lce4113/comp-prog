// CSES Bitwise Operations: All Subarray Xors

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int B = 21, MAXN = 1 << B;

vector<int> conv(vector<int> a, vector<int> b) {
    int n = a.size();
    for (int e = n / 2; e > 0; e /= 2) {
        for (int i = 0; i < n; i += 2 * e) {
            for (int j = 0; j < e; j++) {
                int x = a[i + j], y = a[i + j + e];
                a[i + j] = x + y, a[i + j + e] = x - y;
                x = b[i + j], y = b[i + j + e];
                b[i + j] = x + y, b[i + j + e] = x - y;
            }
        }
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
    for (int e = 1; e < n; e *= 2) {
        for (int i = 0; i < n; i += 2 * e) {
            for (int j = 0; j < e; j++) {
                int x = c[i + j], y = c[i + j + e];
                c[i + j] = (x + y) / 2, c[i + j + e] = (x - y) / 2;
            }
        }
    }
    return c;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n), p(1, 0), f(MAXN);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) p.push_back(p.back() ^ a[i]);
    for (auto v : p) f[v] = 1;
    auto res = conv(f, f);
    vector<int> ans;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        if (p[i] == p[i + 1]) {
            ans.push_back(0);
            break;
        }
    }
    for (int i = 1; i < MAXN; i++) {
        if (res[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}