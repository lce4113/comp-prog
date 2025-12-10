// Codeforces Round 1023: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n;
vector<int> A;

int count(map<int, vector<int>> &mp, int l, int r, int v) {
    return upper_bound(mp[v].begin(), mp[v].end(), r) -
           lower_bound(mp[v].begin(), mp[v].end(), l);
}

int ch() {
    vector<int> a = A;
    reverse(a.begin(), a.end());

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    int mn = *min_element(a.begin(), a.end());

    int ans = 1e18, c = (mn + 1) * n;
    for (int i = mn; mp[i].size(); i++) {
        int pi = mp[i][0];
        int ci = count(mp, 0, mp[i - 1].size() ? mp[i - 1][0] : n, i);
        c = c + pi - ci;
        ans = min(ans, c);
    }
    return ans;
}

int solve() {
    vector<int> a = A;
    reverse(a.begin(), a.end());

    map<int, vector<int>> mp;
    map<int, int> lst;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);

    int c = a[n - 1], tot = a[n - 1];
    stack<pair<int, int>> Q;
    Q.push({n - 1, 1});
    set<pair<int, int>> is;
    map<int, int> store;
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
            int ci = count(mp, i, lst.count(c - 1) ? lst[c - 1] : n, c);
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
    }
    return tot;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t = 1;
    // cin >> t;
    // while (t--) solve();

    for (int i1 = 1; i1 <= 5; i1++) {
        for (int i2 = 1; i2 <= 5; i2++) {
            for (int i3 = 1; i3 <= 5; i3++) {
                for (int i4 = 1; i4 <= 5; i4++) {
                    for (int i5 = 1; i5 <= 5; i5++) {
                        vector<int> b = {i1, i2, i3, i4, i5};
                        for (int i = 1; i <= 5; i++) {
                            n = i;
                            A.clear();
                            for (int j = 0; j < i; j++) A.push_back(b[j]);
                            int a1 = 0, a2 = 0;
                            a1 = solve();
                            a2 = ch();
                            if (a1 != a2) {
                                cout << "ohno\n";
                                cout << a1 << ' ' << a2 << '\n';
                                for (auto x : A) cout << x << ' ';
                                cout << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}