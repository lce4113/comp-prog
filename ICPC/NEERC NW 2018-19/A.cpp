// NEERC NW 2018-19: Problem A

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t, p;
    cin >> t >> p;
    if (p >= 20) {
        long double ans = t;
        ans /= (100 - p);
        ans *= (p + 20);
        cout << fixed << setprecision(10) << ans << '\n';
        return 0;
    }
    long double ans = t;
    ans /= (60 - p);
    ans *= p;
    cout << fixed << setprecision(10) << ans << '\n';
}