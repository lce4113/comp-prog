// CSES Additional Problems II: Stick Divisions

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int x, n;
    cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> Q;
    while (n--) {
        int v;
        cin >> v;
        Q.push(v);
    }
    int ans = 0;
    while (Q.size() > 1) {
        auto c1 = Q.top();
        Q.pop();
        auto c2 = Q.top();
        Q.pop();
        ans += c1 + c2;
        Q.push(c1 + c2);
    }
    cout << ans << '\n';
}