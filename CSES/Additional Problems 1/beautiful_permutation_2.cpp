// CSES Additional Problems I: Beautiful Permutation II

#include <bits/stdc++.h>
using namespace std;

int n;
set<int> rem;

bool test(int x) {
    if (rem.size() == 4) {
        rem.erase(x);
        bool res = (1 + *rem.begin() == *(++rem.begin()) &&
                    1 + *(++rem.begin()) == *(++(++rem.begin())));
        rem.insert(x);
        return !res;
    }
    if (rem.size() == 3) {
        rem.erase(x);
        bool res = (1 + *rem.begin() == *(++rem.begin()));
        rem.insert(x);
        return !res;
    }
    return 1;
}

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return;
    }
    if (n == 4) {
        cout << "2 4 1 3\n";
        return;
    }
    priority_queue<int, vector<int>, greater<int>> Q;
    vector<int> ans(1, 1);
    for (int i = 2; i <= n; i++) Q.push(i);
    for (int i = 2; i <= n; i++) rem.insert(i);
    while (Q.size()) {
        vector<int> cs;
        do {
            cs.push_back(Q.top());
            Q.pop();
        } while (abs(cs.back() - ans.back()) == 1 || !test(cs.back()));
        int m = cs.size();
        for (int i = 0; i < m - 1; i++) Q.push(cs[i]);
        ans.push_back(cs.back());
        rem.erase(cs.back());
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // for (int i = 1; i <= 15; i++) {
    //     n = i;
    solve();
    // }
}
