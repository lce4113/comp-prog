// CSES Graph Algorithms: De Bruijn Sequence

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;

string ans;
int n;
vector<set<int>> g(1 << (MAXN - 1), {0, 1});

void rec(int v) {
    while (g[v].size()) {
        auto to = *g[v].begin();
        g[v].erase(to);
        auto to_val = (v + to * (1 << (n - 1))) / 2;
        rec(to_val);
    }
    ans += '0' + (v & 1);
}

int32_t main() {
    cin >> n;

    if (n == 1) {
        cout << "01\n";
        return 0;
    }

    ans.assign(n - 1, '0');
    rec(0);
    ans.pop_back();

    cout << ans << '\n';
}