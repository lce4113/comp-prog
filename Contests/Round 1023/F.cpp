// Codeforces Round 1023: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const string nl = " ";

map<int, vector<int>> mp;
map<int, int> lst;

int count(int l, int r, int v) {
    return upper_bound(mp[v].begin(), mp[v].end(), r) -
           lower_bound(mp[v].begin(), mp[v].end(), l);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    reverse(a.begin(), a.end());

    mp.clear(), lst.clear();
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);

    int c = a[n - 1], tot = a[n - 1];
    stack<pair<int, int>> Q;
    Q.push({n - 1, 1});
    set<pair<int, int>> is;
    map<int, int> store;
    cout << tot << nl;
    for (int i = n - 2, N = 2; i >= 0; i--, N++) {
        lst[a[i]] = i;
        tot += c + 2;
        while (a[i] <= c) {
            if (Q.empty()) {
                tot = (a[i] + 1) * N;
                c = a[i] - 1;
                break;
            }
            auto [pi, ci] = Q.top();
            Q.pop();
            tot -= pi - i, tot += ci;
            is.erase({store[c], c});
            store.erase(c);
            c--;
        }
        if (a[i] == c + 1) {
            c = a[i];
            int ci = count(i, lst.count(c - 1) ? lst[c - 1] : n, c);
            if (store.count(c - 1)) {
                is.erase({store[c - 1], c - 1});
                is.insert({--store[c - 1], c - 1});
            }
            if (Q.size()) {
                store[c] = i - ci - 1;
                is.insert({store[c], c});
            }
            tot -= ci;
            Q.push({i, ci});
        }
        while (is.size() && i <= is.rbegin()->f) {
            auto ic = is.rbegin()->s;
            while (c >= ic) {
                auto [pi, ci] = Q.top();
                Q.pop();
                tot -= pi - i, tot += ci;
                is.erase({store[c], c});
                store.erase(c);
                c--;
            }
        }
        // for (auto x : is) cout << x.f << ' ' << x.s << '\n';
        cout << tot << nl;
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}