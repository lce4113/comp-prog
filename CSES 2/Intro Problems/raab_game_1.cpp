// CSES Intro Problems: Raab Game I

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO\n";
        return;
    }
    if (a == 0 && b == 0) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    if (a == 0 || b == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    if (a > 1 && b > 1) {
        cout << a << ' ';
        int i = 2;
        for (; i <= a; i++) cout << i - 1 << ' ';
        for (; i < a + b; i++) cout << i + 1 << ' ';
        cout << a + 1 << ' ';
        for (i++; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    if (a == 1) {
        int i = 1;
        for (; i <= b; i++) cout << i + 1 << ' ';
        cout << 1 << ' ';
        for (i++; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    int i = 2;
    cout << a + 1 << ' ';
    for (; i <= a + 1; i++) cout << i - 1 << ' ';
    for (; i <= n; i++) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
