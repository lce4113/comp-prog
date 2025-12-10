// CSES Additional Problems II: Increasing Array II

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int ans = 0;
    priority_queue<int> Q;
    while (n--) {
        int x;
        cin >> x;
        Q.push(x), Q.push(x);
        ans += Q.top() - x;
        Q.pop();
    }
    cout << ans << '\n';
}