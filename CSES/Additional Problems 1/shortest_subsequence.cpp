// CSES Additional Problems I: Shortest Subsequence

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin >> a;
    int n = a.size();
    string DNA = "ACGT";
    vector<vector<int>> jump(n + 1, vector<int>(4, n + 1));
    for (int i = n; i >= 1; i--) {
        jump[i - 1] = jump[i];
        jump[i - 1][DNA.find(a[i - 1])] = i;
    }
    // for (auto x : jump) {
    //     for (auto y : x) cout << y << " ";
    //     cout << '\n';
    // }
    int c = 0;
    string ans;
    while (c <= n) {
        int p = max_element(jump[c].begin(), jump[c].end()) - jump[c].begin();
        ans += DNA[p];
        c = jump[c][p];
    }
    cout << ans << '\n';
}