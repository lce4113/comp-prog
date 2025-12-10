// CSES Sorting & Searching: Towers

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    multiset<int> st;
    for (auto x : a) {
        if (st.empty() || x >= *st.rbegin()) {
            st.insert(x);
        } else {
            st.erase(st.upper_bound(x));
            st.insert(x);
        }
    }
    cout << st.size() << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}