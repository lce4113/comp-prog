// CSES Advanced Techniques: Apples and Bananas

#include <bits/stdc++.h>
using namespace std;

#define int long long
using C = complex<long double>;

void fft(vector<C> &a) {
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<C> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n), rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; i++) {
            rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
        }
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    }
    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                C z = rt[j + k] * a[i + j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}

vector<double> conv(const vector<int> &a, const vector<int> &b) {
    vector<double> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);
    copy(a.begin(), a.end(), in.begin());
    for (int i = 0; i < b.size(); i++) {
        in[i].imag(b[i]);
    }
    fft(in);
    for (C &x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for (int i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> k >> n >> m;
    vector<int> a(k + 1), b(k + 1);
    int x;
    while (n--) {
        cin >> x;
        a[x]++;
    }
    while (m--) {
        cin >> x;
        b[x]++;
    }

    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';
    auto ans = conv(a, b);
    for (int i = 2; i <= 2 * k; i++) {
        cout << (int)round(ans[i]) << ' ';
    }
    cout << '\n';
}