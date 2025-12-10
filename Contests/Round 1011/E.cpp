// Codeforces Round 1011: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e6;

int n;
vector<int> a, b;
// vector<int> mp(MAXN + 1);
unordered_map<int, int> mp;

bool ch(int c) {
    for (auto x : a) mp[x % c]++;
    for (auto x : b) {
        if (--mp[x] < 0) {
            mp[x] = 0;
            for (auto y : a) mp[y % c] = 0;
            return 0;
        }
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

    if (ch(MAXN + 1)) {
        cout << MAXN + 1 << '\n';
        return;
    }

    for (int i = 1; i * i <= sm; i++) {
        if (sm % i) continue;
        if (ch(i)) {
            cout << i << '\n';
            return;
        }
        if (ch(sm / i)) {
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