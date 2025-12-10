// CSES Intro Problems: Creating Strings

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    vector<string> ans;
    do {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
