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
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            ans[1]++;
            continue;
        }
        vector<bool> rl;
        rl.push_back(a.substr(n - i - 1, i) > a.substr(n - i, i));
        for (int j = n - i - 2; j >= 0; j--) {
            char l = a[j], r = a[j + 1];
            rl.push_back(l == r ? rl.back() : r < l);
        }
        reverse(rl.begin(), rl.end());

        cout << i << ": ";
        for (auto x : rl) cout << x << ' ';
        cout << '\n';

        // find dips
        vector<int> dip, gap, gpfs(1, 0);
        dip.push_back(-1);
        if (!rl[0]) dip.push_back(0);
        for (int j = 0; j < n - i - 1; j++) {
            if (rl[j] && !rl[j + 1]) dip.push_back(j + 1);
        }

        cout << "dip: ";
        for (auto x : dip) cout << x << ' ';
        cout << '\n';

        // set up gap and gap prefix sum
        for (int j = 1; j < (int)dip.size(); j++) {
            int x = dip[j] - dip[j - 1];
            if (x > 1) gap.push_back(x - 1);
        }
        sort(gap.begin(), gap.end());
        for (auto x : gap) gpfs.push_back(gpfs.back() + x);
        gap.insert(gap.begin(), 0);

        cout << "gap: ";
        for (auto x : gap) cout << x << ' ';
        cout << '\n';

        // erased as the line moves
        vector<int> es;
        for (auto x : dip) es.push_back(x + 1);
        es.pop_back();
        for (int j = dip.back() + 1; j < n - i + 1; j++) es.push_back(j);

        cout << "es: ";
        for (auto x : es) cout << x << ' ';
        cout << '\n';

        // do stuff with the gaps and the gap pfs
        for (int j = i; j <= n; j++) {
            int c = n - i + 1;
            // remove gaps
            int pos =
                --upper_bound(gap.begin(), gap.end(), j - i) - gap.begin();
            // cout << pos << ' ';
            c -= gpfs[pos] + (j - i) * ((int)gap.size() - pos - 1);
            // remove line
            int ess = es.end() - lower_bound(es.begin(), es.end(), n - j + 1);
            c -= ess;
            cout << j << ' ' << c << ' ' << gpfs[pos] << ' '
                 << (j - i) * ((int)gap.size() - pos - 1) << ' ' << ess << '\n';
            ans[c]++;
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int32_t main() { solve(); }