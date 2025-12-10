// Codeforces Educational Round 169: Problem E

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MAXN = 1e7;

vector<int> sieve(MAXN + 1, 1);
vector<int> g(MAXN + 1, 0);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;
    for (auto x : a) ans ^= g[x];
    cout << (ans == 0 ? "Bob" : "Alice") << '\n';
}

int32_t main() {
    for (int i = 2; i * i <= MAXN; i++) {
        if (sieve[i] != 1) continue;
        for (int j = 2 * i; j <= MAXN; j += i) {
            sieve[j] = sieve[j] == 1 ? i : sieve[j];
        }
    }

    int curr = 0;
    for (int i = 0; i < MAXN; i++) {
        if (i % 2 == 0) {
            g[i] = 0;
            continue;
        }
        int p = sieve[i];
        g[i] = (p == 1 ? ++curr : g[p]);
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}