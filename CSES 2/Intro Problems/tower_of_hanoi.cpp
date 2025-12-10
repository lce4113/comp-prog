// CSES Intro Problems: Tower of Hanoi

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int, int>> ans;

void move(int n, int from, int to, int empty) {
    if (n == 0) return;
    move(n - 1, from, empty, to);
    ans.push_back({from, to});
    move(n - 1, empty, to, from);
}

void solve() {
    int n;
    cin >> n;
    move(n, 1, 3, 2);
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x.f << ' ' << x.s << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
