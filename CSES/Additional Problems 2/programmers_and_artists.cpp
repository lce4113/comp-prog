// CSES Additional Problems II: Programmers and Artists

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, n;
    cin >> a >> b >> n;
    vector<pair<int, int>> pa(n);
    for (auto &x : pa) {
        cin >> x.f >> x.s;
    }
    sort(pa.rbegin(), pa.rend());

    vector<int> right(n + 1);
    priority_queue<int> Q;
    for (int i = n - 1; i >= a; i--) {
        Q.push(pa[i].s);
        if (i < a + b) {
            right[i] = right[i + 1] + Q.top();
            Q.pop();
        }
    }
    while (Q.size()) Q.pop();
    int ans = 0;
    int left = 0;
    for (int i = 0; i < a; i++) {
        left += pa[i].f;
        Q.push(pa[i].s - pa[i].f);
    }
    for (int i = a; i < a + b; i++) {
        ans = max(ans, left + right[i]);
        left += pa[i].f;
        Q.push(pa[i].s - pa[i].f);
        left += Q.top();
        Q.pop();
    }
    ans = max(ans, left + right[a + b]);
    cout << ans << '\n';
}