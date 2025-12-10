#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    int curr = 1, ans = 1;
    for (int i = 1; i < n; i++) {
        curr *= 4;
        curr ^= i;
        curr %= 6;
        if (curr == 1) ans++;
    }
    cout << ans << '\n';
}