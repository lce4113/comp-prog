#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef ONLINE_JUDGE
    ifstream cin("huffman.in");
    ofstream cout("huffman.out");
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (auto x : a) Q.push(x);
    int ans = 0;
    while (Q.size() != 1) {
        auto v1 = Q.top();
        Q.pop();
        auto v2 = Q.top();
        Q.pop();
        Q.push(v1 + v2);
        ans += v1 + v2;
    }
    cout << ans << '\n';
}