// CSES Sorting & Searching: Josephus Problem I

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int c = 2;;) {
        cout << c << ' ';
        st.erase(c);
        if (st.empty()) break;
        auto it = st.lower_bound(c);
        if (it == st.end()) it = st.begin();
        if (++it == st.end()) it = st.begin();
        c = *it;
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}