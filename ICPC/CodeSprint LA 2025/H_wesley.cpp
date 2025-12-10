#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (a[0] != 0 || b[1] != 0) {
        cout << 0 << "\n";
        return 0;
    }

    int d = a[1];

    if (b[0] != d) {
        cout << 0 << "\n";
        return 0;
    }

    if (d == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> cv(2, vector<int>(n));
    vector<vector<int>> tmp(d);

    vector<int> sm(3);

    for (int i = 2; i < n; i++) {
        if (b[i] == 0 || a[i] == 0) {
            cout << 0 << "\n";
            return 0;
        }

        if (abs(a[i] - b[i]) > d) {
            cout << 0 << "\n";
            return 0;
        }

        // is on one side of the thing
        if (abs(a[i] - b[i]) == d) {
            if (a[i] > b[i]) {
                // closer to b[i]
                cv[1][b[i] - 1]++;
                sm[1]++;
            } else {
                cv[0][a[i] - 1]++;
                sm[0]++;
            }
            continue;
        }

        // is between both
        if (a[i] + b[i] < d || (a[i] + b[i] - d) % 2) {
            cout << 0 << "\n";
            return 0;
        }
        int cd = (a[i] + b[i] - d) / 2;
        tmp[a[i] - cd].push_back(cd);
    }

    ll ans = 1;
    for (int j = 0; j < 2; j++) {
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (tot == sm[j]) {
                break;
            }
            if (cv[j][i] == 0) {
                cout << 0 << "\n";
                return 0;
            }
            tot += cv[j][i];
            if (i == 0) {
                continue;
            }

            ans = ans * binpow(cv[j][i - 1], cv[j][i]) % MOD;
        }
    }

    // handle nodes which are between both

    for (int i = 1; i < d; i++) {
        sort(tmp[i].begin(), tmp[i].end());
        if (tmp[i].empty() || tmp[i][0] != 0) {
            cout << 0 << "\n";
            return 0;
        }
        if (tmp[i].size() == 1) {
            continue;
        }
        if (tmp[i][1] == 0) {
            cout << 0 << "\n";
            return 0;
        }
        vector<int> cur;
        int cc = 0;
        for (int j = 1; j < tmp[i].size(); j++) {
            if (tmp[i][j] != tmp[i][j - 1] && tmp[i][j] - 1 != tmp[i][j - 1]) {
                cout << 0 << "\n";
                return 0;
            }
            cc++;

            if (j == tmp[i].size() - 1 || tmp[i][j + 1] != tmp[i][j]) {
                cur.push_back(cc);
                cc = 0;
            }
        }

        for (int j = 1; j < cur.size(); j++) {
            ans = ans * binpow(cur[j - 1], cur[j]) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}