#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<int> a, b, c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            a.insert(i);
        else if (s[i] == 'B')
            b.insert(i);
        else
            c.insert(i);
    }
    int ans = 0;
    while (a.size() || b.size() || c.size()) {
        int idx = 0;
        ans++;
        while (a.size() || b.size() || c.size()) {
            int miniA = 1e9, miniB = 1e9, miniC = 1e9;
            if (a.size() && a.lower_bound(idx) != a.end()) {
                miniA = *a.lower_bound(idx);
            }
            if (b.size() && b.lower_bound(idx) != b.end()) {
                miniB = *b.lower_bound(idx);
            }
            if (c.size() && c.lower_bound(idx) != c.end()) {
                miniC = *c.lower_bound(idx);
            }
            if (miniA <= miniC && miniB <= miniC) {
                if (miniC == 1e9) break;
                a.erase(miniA);
                b.erase(miniB);
                c.erase(miniC);
                idx = miniC;
            } else if (miniA <= miniB && miniC <= miniB) {
                if (miniB == 1e9) break;
                a.erase(miniA);
                b.erase(miniB);
                c.erase(miniC);
                idx = miniB;
            } else if (miniC <= miniA && miniB <= miniA) {
                if (miniA == 1e9) break;
                a.erase(miniA);
                b.erase(miniB);
                c.erase(miniC);
                idx = miniA;
            }
        }
    }
    cout << ans << endl;
}
int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}