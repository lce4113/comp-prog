// CSES String Algorithms: Finding Patterns

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin >> a;
    int n = a.size();

    vector<int> order(n), eq(2 * n);
    for (int i = 0; i < n; i++) order[i] = i, eq[i] = a[i] - 'a' + 1;
    for (int e = 1; e < n; e *= 2) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({eq[i], eq[i + e]});
        }
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(),
             [&](int x, int y) { return pairs[x] < pairs[y]; });
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (i != 0 && pairs[order[i]] != pairs[order[i - 1]]) c++;
            eq[order[i]] = c;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string b;
        cin >> b;
        int l = -1, r = n;
        bool ok = 0;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a.substr(order[m], b.size()) == b) {
                cout << "YES\n";
                ok = 1;
                break;
            }
            if (a.substr(order[m], b.size()) >= b) {
                r = m;
            } else {
                l = m;
            }
        }
        if (ok) continue;
        cout << "NO\n";
    }
}