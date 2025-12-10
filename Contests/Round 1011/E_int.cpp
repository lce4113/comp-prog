// Codeforces Round 1011: Problem E

#include <bits/stdc++.h>
using namespace std;

const int C = 1e6 + 5;

int n;
vector<int> a, b;
int cnt[C];
long long s;

bool check(int k) {
    for (int i = 0; i < n; i++) cnt[a[i] % k]++;
    for (int i = 0; i < n; i++)
        if (--cnt[b[i]] < 0) {
            cnt[b[i]] = 0;
            for (int j = 0; j < n; j++) cnt[a[j] % k] = 0;
            return 0;
        }
    return 1;
}

void solve() {
    cin >> n;
    a.clear(), b.clear();
    a.assign(n, 0), b.assign(n, 0);
    long long sm = 0;
    for (auto &x : a) {
        cin >> x;
        sm += x;
    }
    for (auto &x : b) {
        cin >> x;
        sm -= x;
    }

    if (check(C + 1)) {
        cout << C + 1 << '\n';
        return;
    }

    for (int i = 1; 1ll * i * i <= sm; i++) {
        if (sm % i) continue;
        if (check(i)) {
            cout << i << '\n';
            return;
        }
        if (check(sm / i)) {
            cout << sm / i << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}