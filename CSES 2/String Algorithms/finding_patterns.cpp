// CSES String Algorithms: Finding Patterns

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXN = 1e5;
int eq[2 * MAXN], eq2[2 * MAXN];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin >> a;
    int n = a.size();

    vector<int> order;
    vector<vector<int>> buckets1(27);
    for (int i = 0; i < n; i++) buckets1[a[i] - 'a' + 1].push_back(i);
    int c = 0;
    for (auto bucket : buckets1) {
        if (bucket.size()) c++;
        for (auto p : bucket) eq[p] = c, order.push_back(p);
    }
    for (int e = 1; e < n; e *= 2) {
        vector<int> buckets[c + 1];
        for (int i = n + e - 1; i >= n; i--) {
            buckets[eq[i - e]].push_back(i - e);
        }
        for (int i = 0; i < n; i++) {
            if (order[i] < e) continue;
            buckets[eq[order[i] - e]].push_back(order[i] - e);
        }
        order.clear();
        c = 0;
        pair<int, int> lst = {-1, -1};
        for (auto bucket : buckets) {
            for (auto p : bucket) {
                order.push_back(p);
                pair<int, int> cur = {eq[p], eq[p + e]};
                if (cur != lst) c++;
                eq2[p] = c;
                lst = cur;
            }
        }
        swap(eq, eq2);
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