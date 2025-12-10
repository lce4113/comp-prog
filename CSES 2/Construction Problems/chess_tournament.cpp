// CSES Construction Problems: Chess Tournament

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) Q.emplace(a[i], i);
    vector<pair<int, int>> ans;
    while (Q.top().f) {
        if (Q.empty() || Q.top().f == 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        auto c1 = Q.top();
        Q.pop();
        vector<pair<int, int>> nxt;
        nxt.push_back(c1);
        nxt[0].f = 0;
        while (c1.f) {
            if (Q.empty() || Q.top().f == 0) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            auto c2 = Q.top();
            Q.pop();
            ans.emplace_back(c1.s + 1, c2.s + 1);
            c1.f--, c2.f--;
            nxt.push_back(c2);
        }
        for (auto c : nxt) Q.push(c);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.f << ' ' << x.s << '\n';
}