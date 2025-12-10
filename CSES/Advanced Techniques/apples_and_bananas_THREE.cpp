#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
typedef long long ll;
const double PI = acos(-1);

void fft(vector<cd> &p) {
    int n = p.size();
    if (n == 1) return;
    vector<cd> e(n / 2), o(n / 2);
    for (int j = 0; j < n / 2; j++) {
        e[j] = p[2 * j];
        o[j] = p[2 * j + 1];
    }
    fft(e);
    fft(o);
    for (int j = 0; j < n / 2; j++) {
        cd w(cos(2 * PI * j / n), sin(2 * PI * j / n));
        p[j] = e[j] + w * o[j];
        p[j + n / 2] = e[j] - w * o[j];
    }
}

void ifft(vector<cd> &p) {
    int n = p.size();
    if (n == 1) return;
    vector<cd> e(n / 2), o(n / 2);
    for (int j = 0; j < n / 2; j++) {
        cd w(cos(2 * PI * j / n), sin(2 * PI * j / n));
        e[j] = (p[j] + p[j + n / 2]) / (cd)2;
        o[j] = (p[j] - p[j + n / 2]) / ((cd)2 * w);
    }
    ifft(e);
    ifft(o);
    for (int j = 0; j < n / 2; j++) {
        p[2 * j] = e[j];
        p[2 * j + 1] = o[j];
    }
}

vector<ll> mult(vector<int> p, vector<int> q) {
    int n = 1;
    while (n < p.size() + q.size() - 1) n *= 2;
    vector<cd> pc(n), qc(n);
    for (int i = 0; i < p.size(); i++) pc[i] = p[i], qc[i] = q[i];

    fft(pc);
    fft(qc);
    vector<cd> rv(n);
    for (int j = 0; j < n; j++) {
        rv[j] = pc[j] * qc[j];
    }
    ifft(rv);
    vector<ll> res(n);
    for (int j = 0; j < n; j++) {
        res[j] = round(rv[j].real());
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }

    vector<ll> tmp = mult(a, b);
    for (int i = 2; i <= 2 * k; i++) {
        cout << tmp[i] << " ";
    }
    cout << "\n";
    return 0;
}