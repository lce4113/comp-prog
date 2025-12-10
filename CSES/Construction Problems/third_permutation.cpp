// CSES Construction Problems: Third Permutation

#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, ans;
set<int> rem;
vector<int> ch;
int n;

void check() {
    if (a[n - 3] != ch[0] && b[n - 3] != ch[0] && a[n - 2] != ch[1] &&
        b[n - 2] != ch[1] && a[n - 1] != ch[2] && b[n - 1] != ch[2]) {
        ans[n - 3] = ch[0], ans[n - 2] = ch[1], ans[n - 1] = ch[2];
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
        exit(0);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    if (n == 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    a.assign(n, 0), b.assign(n, 0);
    ans.assign(n, 0);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    for (int i = 1; i <= n; i++) rem.insert(i);
    for (int i = 0; i < n - 3; i++) {
        auto it = rem.begin();
        while (*it == a[i] || *it == b[i]) it++;
        ans[i] = *it;
        rem.erase(it);
    }
    for (auto x : rem) ch.push_back(x);
    do {
        check();
    } while (next_permutation(ch.begin(), ch.end()));
}