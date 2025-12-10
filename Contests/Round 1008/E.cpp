// Codeforces Round 1008: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int q(int n) {
    cout << n << endl;
    int res;
    cin >> res;
    return res;
}

int aq() {
    cout << "!" << endl;
    int res;
    cin >> res;
    return res;
}

void res(int n) { cout << n << endl; }

void solve() {
    // b = ...010101
    // a = ...101010
    // int N = 6;
    int N = 30;
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2)
            a += (1 << i);
        else
            b += (1 << i);
    }
    // cout << a << ' ' << b << '\n';
    int r1 = q(b), r2 = q(a);
    r1 >>= 1;
    vector<int> bs(N);
    for (int i = 0; i < N; i++) {
        if (i % 2) {
            bs[i] = (r1 & 3) - 1;
            r1 >>= 2;
        } else {
            bs[i] = (r2 & 3) - 1;
            r2 >>= 2;
        }
    }
    bs[0]++;
    // for (auto x : bs) cout << x << ' ';
    // cout << '\n';
    int q = aq();
    int ans = 2 * q;
    for (int i = 0; i < 30; i++) {
        if (q % 2 == 0) {
            ans += bs[i] * (1 << i);
        }
        q /= 2;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}