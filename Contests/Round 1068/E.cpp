// Codeforces Round 1068: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<int> a, p;

bool q(int x, int y) {
    if (x == y) return 1;
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int i, j;
    cin >> i >> j;
    i--, j--;
    swap(p[a[i]], p[a[j]]);
    swap(a[i], a[j]);
    return ((i == x && j == y) || (i == y && j == x));
}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    p.assign(n, 0);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    for (int i = 0; i < n; i++) p[a[i]] = i;
    for (int i = 1; i <= n / 2; i++) {
        do {
            q(p[i - 1], i - 1);
        } while (p[i - 1] != i - 1);
        int x = p[n - i], y = n - i;
        do {
            q(x, y);
        } while (p[n - i] != n - i || p[i - 1] != i - 1);
    }
    cout << "!" << endl;
    //  1 ...  6 ... 11 <-- indices
    //  1 ... 11 ...  6 <-- initial
    // 11 ...  1 ...  6 <-- fail
    // 11 ...  6 ...  1 <-- success
    //  1 ... 11 ...  1 <-- fail
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}