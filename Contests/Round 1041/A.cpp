// Codeforces Round 1041: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> b;
    for (auto x : a) b.insert(x);
    b.erase(-1);
    if (b.empty()) {
        cout << "YES\n";
        return;
    }
    if (b.size() == 1 && *b.begin() != 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}