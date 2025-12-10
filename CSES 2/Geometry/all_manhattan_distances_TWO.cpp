// CSES Geometry: All Manhattan Distances

#include <bits/stdc++.h>
using namespace std;

#define L __int128

void print(L x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x) {
        s += '0' + x % 10;
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a, a + n);
    sort(b, b + n);

    L ans = 0, sm = 0;
    for (int i = 0; i < n; i++) {
        L tmp = a[i];
        tmp *= i;
        ans += tmp - sm;
        sm += a[i];
    }
    sm = 0;
    for (int i = 0; i < n; i++) {
        L tmp = b[i];
        tmp *= i;
        ans += tmp - sm;
        sm += b[i];
    }

    print(ans);
}