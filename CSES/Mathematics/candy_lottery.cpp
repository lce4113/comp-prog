// CSES Mathematics: Candy Lottery

#include <bits/stdc++.h>
using namespace std;

long double binexp(long double a, int b) {
    long double res = 1;
    for (; b; b /= 2, a *= a)
        if (b % 2) res *= a;
    return res;
}

long double C(int a, int b) {
    if (b > a - b) return C(a, a - b);
    long double ans = 1;
    for (int i = a - b + 1; i <= a; i++) ans *= i;
    for (int i = 1; i <= b; i++) ans /= i;
    return ans;
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    long double ans = 0;
    for (int c = 1; c <= k; c++) {
        long double prob = 0;
        for (int i = 1; i <= n; i++) {
            long double x = (long double)(c - 1) / k;
            prob += binexp(x, n - i) * C(n, i) / binexp(k, i);
        }
        ans += prob * c;
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
