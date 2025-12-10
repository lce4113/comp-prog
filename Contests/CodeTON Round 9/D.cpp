// CodeTON Round 9: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MAXN = 1e5 + 10;
vector<bool> sieve(MAXN + 1, true);

int pfac(int n) {
    int ans = 0;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) n /= i, ans++;
    }

    if (n >= 2) ans++;

    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());

    // for (int i = 1; i <= 10; i++) {
    //     cout << i << ' ' << pfac(i) << '\n';
    // }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int p = pfac(i);
        if (p >= a.size()) {
            cout << "-1\n";
            return;
        }
        ans.push_back(a[p]);
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    // sieve[0] = sieve[1] = false;
    // for (int i = 2; i * i <= MAXN; i++) {
    //     if (!sieve[i]) continue;
    //     for (int k = 2 * i; k <= MAXN; k += i) sieve[k] = false;
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}