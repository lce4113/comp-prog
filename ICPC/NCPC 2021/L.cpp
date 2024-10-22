#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int y, c1, c2;
        cin >> y >> c1 >> c2;
        ans = min(ans, y + lcm(c1, c2));
    }
    cout << ans << '\n';
}