// Codeforces Round 995: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(k);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    set<int> B;
    for (auto x : b) B.insert(x);
    set<int> ms;
    for (int c = 1; c <= n; c++) {
        if (!B.count(c)) ms.insert(c);
    }
    for (auto x : a) {
        if (ms.size() == 0)
            cout << '1';
        else if (ms.size() >= 2)
            cout << '0';
        else if (ms.count(x))
            cout << '1';
        else
            cout << '0';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}