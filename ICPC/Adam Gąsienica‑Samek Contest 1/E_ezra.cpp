#include <bits/stdc++.h>

using namespace std;

mt19937 rng(30);
const int MAXK = 1e7 + 5;
int z[MAXK];

vector<int> oc[MAXK];

int ct(int l, int r, int v) {
    return upper_bound(oc[v].begin(), oc[v].end(), r) -
           lower_bound(oc[v].begin(), oc[v].end(), l);
}

int main() {
    for (int i = 2; i < MAXK; i++) {
        if (!z[i]) {
            for (int j = i; j < MAXK; j += i) {
                z[j] = i;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> on;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int pr = 1;
        while (a[i] != 1) {
            int x = z[a[i]];
            while (a[i] % x == 0) {
                a[i] /= x;
            }
            pr *= x;
        }
        a[i] = pr;
        if (z[a[i]] == a[i]) {
            on.push_back(i);
        }
        oc[a[i]].push_back(i);
    }

    vector<int> pfs(n + 1);
    for (int i = 0; i < n; i++) {
        if (z[a[i]] == a[i]) {
            pfs[i + 1] = pfs[i] + 1;
        } else {
            pfs[i + 1] = pfs[i];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = ct(l, r, 1);
        if (ans == r - l + 1) {
            cout << -1 << "\n";
            continue;
        }
        int tv = pfs[r + 1] - pfs[l];
        int lr = lower_bound(on.begin(), on.end(), l) - on.begin();
        if (lr == on.size() || on[lr] > r || tv == 0) {
            cout << ans << "\n";
            continue;
        }

        if (ct(l, r, a[on[lr]]) == tv) {
            if (r - l + 1 == ans + tv) {
                cout << -1 << "\n";
                continue;
            } else {
                cout << ans + tv << "\n";
                continue;
            }
        }

        bool ok = 0;
        for (int i = 0; i < 30; i++) {
            int ts = (rng() % tv) + lr;
            int tl = ct(l, r, a[on[ts]]);
            if (tl > tv / 2) {
                ok = 1;
                cout << ans + tl << "\n";
                break;
            }
        }

        if (!ok) {
            cout << ans + (tv + 1) / 2 << "\n";
            continue;
        }
    }
    return 0;
}