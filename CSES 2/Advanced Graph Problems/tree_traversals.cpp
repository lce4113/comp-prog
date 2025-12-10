// CSES Advanced Graph Problems: Tree Traversals

#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, ans;
map<int, int> pos;

void dfs(int l1, int r1, int l2, int r2) {
    if (l2 > r2) return;
    int root = a[l1], L = pos[root] - l2;
    dfs(l1 + 1, l1 + L, l2, pos[root] - 1);
    dfs(l1 + L + 1, r1, pos[root] + 1, r2);
    cout << root << ' ';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) pos[b[i]] = i;

    dfs(0, n - 1, 0, n - 1);
    cout << '\n';
}