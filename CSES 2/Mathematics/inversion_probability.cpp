// CSES Mathematics: Inversion Probability

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> a;

long double prob(int x, int y) {
    // x = 7, y = 5
    if (x > y) return y * (y - 1) / 2 + (x - y) * y;
    // x = 5, y = 7
    return x * (x - 1) / 2;
}

int32_t main() {
    cin >> n;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += prob(a[i], a[j]) / (long double)(a[i] * a[j]);
            // cout << a[i] << ' ' << a[j] << ' ' << prob(a[i], a[j]) << '\n';
        }
    }

    ans *= 1e6;
    int dig1 = fmod(ans * 10, 10);
    int dig2 = fmod(ans, 10);
    if (dig1 == 5) {
        if (dig2 % 2)
            ans += 1e-6;
        else
            ans -= 1e-6;
    }
    ans = llround(ans);
    ans /= 1e6;
    cout << fixed << setprecision(6) << ans << '\n';
}