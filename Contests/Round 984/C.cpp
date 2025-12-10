// Codeforces Round 984: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string s;
    int q;
    cin >> s >> q;
    set<int> pos;
    int n = s.size();
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' &&
            s[i + 3] == '0') {
            pos.insert(i);
        }
    }
    while (q--) {
        int t;
        char v;
        cin >> t >> v;
        t--;
        s[t] = v;
        pos.erase(t);
        pos.erase(t - 1);
        pos.erase(t - 2);
        pos.erase(t - 3);
        for (int i = 0; i < 4; i++) {
            if (t - i + 3 >= n) continue;
            if (s[t - i] == '1' && s[t - i + 1] == '1' && s[t - i + 2] == '0' &&
                s[t - i + 3] == '0') {
                pos.insert(t - i);
            }
        }
        cout << (pos.size() ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}