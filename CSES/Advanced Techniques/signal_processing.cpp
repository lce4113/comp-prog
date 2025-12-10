// CSES Advanced Techniques: Signal Processing

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define C complex<double>
const double PI = acos(-1);

void fft(vector<C> &a) {
    int n = a.size();
    if (n == 1) return;
    vector<C> e(n / 2), o(n / 2);
    for (int i = 0; i < n / 2; i++) e[i] = a[2 * i], o[i] = a[2 * i + 1];
    fft(e), fft(o);
    for (int i = 0; i < n / 2; i++) {
        double ang = 2 * PI * i / n;
        C w(cos(ang), sin(ang));
        a[i] = e[i] + w * o[i];
        a[i + n / 2] = e[i] - w * o[i];
    }
}

void ifft(vector<C> &a) {
    int n = a.size();
    if (n == 1) return;
    vector<C> e(n / 2), o(n / 2);
    for (int i = 0; i < n / 2; i++) {
        double ang = 2 * PI * i / n;
        C w(cos(ang), sin(ang));
        e[i] = (a[i] + a[i + n / 2]) / (C)2;
        o[i] = (a[i] - a[i + n / 2]) / (C)2 / w;
    }
    ifft(e), ifft(o);
    for (int i = 0; i < n / 2; i++) a[2 * i] = e[i], a[2 * i + 1] = o[i];
}

vector<int> conv(vector<int> &a, vector<int> &b) {
    int N = a.size() + b.size() - 1, n = 1 << (1 + __lg(N));
    vector<C> A(n), B(n), AB(n);
    for (int i = 0; i < a.size(); i++) A[i] = a[i], B[i] = b[i];
    fft(A), fft(B);
    for (int i = 0; i < n; i++) AB[i] = A[i] * B[i];
    ifft(AB);
    vector<int> ab(N);
    for (int i = 0; i < N; i++) ab[i] = round(AB[i].real());
    return ab;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(max(n, m)), b(max(n, m));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[m - 1 - i];
    auto c = conv(a, b);
    for (int i = 0; i < n + m - 1; i++) cout << c[i] << ' ';
    cout << '\n';
}