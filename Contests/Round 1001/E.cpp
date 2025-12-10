// Codeforces Round 1001: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

map<int, vector<int>> adj;
map<int, int> cs;
vector<int> a;
vector<int> ps;

int rec(int c, int p, int v) {
    ps[c] = p;
    int ans = (a[c] == v);
    for (auto x : adj[c]) {
        if (x == p) continue;
        ans += rec(x, c, v);
    }
    cs[c] = ans;
    return ans;
}

void solve() {
    adj.clear();
    cs.clear();
    a.clear();
    ps.clear();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        ps.push_back(0);
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    set<int> st;
    for (auto x : a) st.insert(x);
    vector<int> b;
    for (auto x : st) b.push_back(x);
    reverse(b.begin(), b.end());
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';

    if (b.size() == 1) {
        cout << "0\n";
        return;
    }

    rec(0, -1, b[0]);

    // for (auto x : cs) cout << x.f << ' ' << x.s << '\n';
    // cout << '\n';

    for (int i = 0; i < n; i++) {
        if (a[i] == b[1] && cs[i] < (int)mp[b[0]].size()) {
            // cout << b[1] << ' ' << cs[i] << ' ' << mp[b[0]] << '\n';
            cout << i + 1 << '\n';
            return;
        }
    }

    for (int i = 2; i < (int)b.size(); i++) {
        for (auto x : mp[b[i]]) {
            if (cs[x] == 0) {
                cout << x + 1 << '\n';
                return;
            }
        }
    }

    // for (auto x : ps) cout << x << ' ';
    // cout << '\n';

    int cp = mp[b[1]][0];
    while (cp != 0) {
        // cout << ps[cp] << ' ' << cp << '\n';
        if (a[ps[cp]] > a[cp]) {
            cout << cp + 1 << '\n';
            return;
        }
        cp = ps[cp];
    }

    cout << "0\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}