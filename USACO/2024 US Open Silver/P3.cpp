// USACO 2024 US Open Contest, Silver
// Problem 3. "The 'Winning' Gene"

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    vector<char> b;
    for (auto x : a) b.push_back(x);
    sort(b.begin(), b.end());
    vector<int> srnk, rnk(n + 1, 0);
    for (auto x : a) {
        int p = lower_bound(b.begin(), b.end(), x) - b.begin();
        srnk.push_back(p);
    }

    // for (auto x : srnk) cout << x << ' ';
    // cout << '\n';

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> prnk, prnk2;
        for (int j = 0; j < n - i + 1; j++) {
            prnk.push_back({srnk[j], rnk[j + 1]});
        }
        prnk2 = prnk;
        sort(prnk.begin(), prnk.end());
        vector<int> nrnk;
        for (auto x : prnk2) {
            int p = lower_bound(prnk.begin(), prnk.end(), x) - prnk.begin();
            nrnk.push_back(p);
        }
        rnk = nrnk;

        // for (auto x : rnk) cout << x << ' ';
        // cout << '\n';

        vector<int> gap(n, 0);
        stack<pair<int, int>> S;
        S.push({-1, -1});
        for (int j = 0; j <= n - i; j++) {
            int c = rnk[j];
            while (c < S.top().f) {
                // cout << c << '<' << S.top().f << ' ' << S.top().s << '\n';
                S.pop();
            }
            // cout << c << ' ' << S.top().f << ' ' << S.top().s << '\n';
            gap[j] = S.top().s;
            S.push({c, j});
        }
        stack<pair<int, int>> Sr;
        Sr.push({-1, n - i + 1});
        for (int j = n - i; j >= 0; j--) {
            int c = rnk[j];
            while (c <= Sr.top().f) Sr.pop();
            gap[j] = Sr.top().s - gap[j];
            Sr.push({c, j});
        }

        // cout << "gap: ";
        // for (auto x : gap) cout << x << ' ';
        // cout << '\n';

        vector<int> gs(n + 1, 0);
        for (int j = 0; j < n; j++) gs[gap[j] + i - 1]++;
        int c = n - i + 1;
        for (int j = i; j <= n; j++) {
            c -= gs[j];
            // cout << c << ' ';
            ans[c]++;
        }
        // cout << '\n';
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int32_t main() {
    // cout << strcmp("A", "B") << '\n';
    // cout << strcmp("A", "!") << '\n';
    solve();
}