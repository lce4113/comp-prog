// Codeforces Educational Round 182: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (reduce(a.begin(), a.end()) % 3 == 0) {
        cout << "1 2" << '\n';
    } else {
        cout << "0 0\n";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}