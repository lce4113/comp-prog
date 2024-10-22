#include <bits/stdc++.h>
using namespace std;

map<string, map<string, bool>> dp;

bool rec(string x, string s) {
    if (dp[x][s]) return dp[x][s];
    // cout << x << ' ' << s << '\n';
    int N = x.size(), M = s.size();
    for (int i = 0, j = 0;; i++, j++) {
        if (s[j] == '*') {
            // cout << j << '\n';
            j++;
            if (j == M) {
                dp[x][s] = true;
                return true;
            }
            for (; i < N; i++) {
                if (x[i] == s[j] &&
                    rec(x.substr(i, N - i), s.substr(j, M - j))) {
                    dp[x][s] = true;
                    return true;
                }
            }
        }
        if (x[i] != s[j]) {
            dp[x][s] = false;
            return false;
        }
        if (i >= N || j >= M) {
            if (i == N && j == M) {
                dp[x][s] = true;
                return true;
            }
            dp[x][s] = false;
            return false;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<string> ans;
    for (auto x : a) {
        if (rec(x, s)) ans.push_back(x);
    }
    for (auto x : ans) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}