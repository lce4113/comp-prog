// Codeforces Pinely Round 4: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n <= 5) {
        vector<int> as = {1, 2, 2, 3, 3, 4};
        vector<int> ans;
        set<int> st;
        for (int i = 0; i < n; i++) {
            ans.push_back(as[i]);
            st.insert(as[i]);
        }
        cout << st.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(i % 4 + 1);
    }
    cout << "4\n";
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}