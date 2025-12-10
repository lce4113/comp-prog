#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s == "P=NP") {
        cout << "skipped\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '+') {
            int x = stoi(s.substr(0, i + 1));
            int y = stoi(s.substr(i + 1, (int)s.size() - i));
            // cout << x << ' ' << y << '\n';
            ans = x + y;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}