// Codeforces Round 1022: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;
map<int, int> mem;

int q(int p) {
    if (mem.count(p)) return mem[p];
    cout << "? " << p << endl;
    int x;
    cin >> x;
    mem[p] = x;
    return x;
}

void res(int a) {
    if (a == -1) {
        cout << "! -1" << endl;
        return;
    }
    cout << "! " << a << ' ' << (n - a) << endl;
}

void solve() {
    mem.clear();

    cin >> n >> k;
    if (n == 2 * k) {
        res(k);
        return;
    }
    int L = k, R = n - k + 1;
    bool ok = 0;
    for (int i = n - k + 1; i <= n; i++) {
        int lp = (i - 1 + k) % k + 1, rp = i;
        int x = q(lp), y = q(rp);
        if (x == y) continue;
        int l = 0, r = (rp - lp) / k, m = (l + r) / 2;
        for (; r - l > 1; m = (l + r) / 2) {
            if (q(m * k + lp) == x)
                l = m;
            else
                r = m;
        }
        L = max(L, l * k + lp);
        R = min(R, r * k + lp);
        ok = 1;
        break;
    }
    if (!ok) {
        res(-1);
        return;
    }
    // 123123132
    //     L Rl
    for (int i = L + 1; i < R; i++) {
        if (q(i) != q(i + k)) L = i;
    }
    for (int i = R - 1; i > L; i--) {
        if (q(i) != q(i - k)) R = i;
    }
    if (L + 1 == R) {
        res(L);
        return;
    }
    res(-1);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}