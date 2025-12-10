// CSES Additional Problems I: Two Array Average

#include <bits/stdc++.h>
using namespace std;

#define int long double

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n), pa(n), pb(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    pa[0] = a[0], pb[0] = b[0];
    for (int i = 1; i < n; i++) {
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
    }
    int mxa = -1, mxb = -1, a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++) {
        if (pa[i] / (i + 1) > mxa) mxa = pa[i] / (i + 1), a1 = i + 1;
        if (pb[i] / (i + 1) > mxb) mxb = pb[i] / (i + 1), a2 = i + 1;
        // cout << pa[i] / (i + 1) << ' ' << pb[i] / (i + 1) << '\n';
    }
    cout << a1 << ' ' << a2 << '\n';
}