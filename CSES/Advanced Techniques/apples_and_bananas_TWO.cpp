// CSES Advanced Techniques: Apples and Bananas

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define C complex<double>
const double PI = acos(-1);

void fft(vector<C> &p) {
    int n = p.size();
    if (n == 1) return;
    vector<C> e(n / 2), o(n / 2);
    for (int i = 0; i < n / 2; i++) e[i] = p[i * 2], o[i] = p[i * 2 + 1];
    fft(e), fft(o);
    for (int i = 0; i < n / 2; i++) {
        double ang = 2 * PI * i / n;
        C w(cos(ang), sin(ang));
        p[i] = e[i] + w * o[i];
        p[i + n / 2] = e[i] - w * o[i];
    }
}

void ifft(vector<C> &p) {
    int n = p.size();
    if (n == 1) return;
    vector<C> e(n / 2), o(n / 2);
    for (int i = 0; i < n / 2; i++) {
        double ang = 2 * PI * i / n;
        C w(cos(ang), sin(ang));
        e[i] = (p[i] + p[i + n / 2]) / (C)2;
        o[i] = (p[i] - p[i + n / 2]) / ((C)2 * w);
    }
    ifft(e), ifft(o);
    for (int i = 0; i < n / 2; i++) p[2 * i] = e[i], p[2 * i + 1] = o[i];
}

vector<int> conv(vector<int> &a, vector<int> &b) {
    int N = a.size() + b.size() - 1, n = 1;
    while (n < N) n *= 2;
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

    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(k + 1), b(k + 1);
    int v;
    while (n--) {
        cin >> v;
        a[v]++;
    }
    while (m--) {
        cin >> v;
        b[v]++;
    }
    vector<int> c = conv(a, b);
    for (int i = 2; i <= 2 * k; i++) cout << c[i] << ' ';
    cout << '\n';
}