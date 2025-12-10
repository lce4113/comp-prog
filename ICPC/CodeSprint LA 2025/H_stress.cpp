#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
typedef long long ll;

const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2)
        if (b % 2) res *= a, res %= MOD;
    return res;
}

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

int n;
vector<int> a, b;

int check() {
    if (a[0] != 0 || b[1] != 0) return 0;

    int d = a[1];

    if (b[0] != d) return 0;
    if (d == 0) return 0;

    vector<vector<int>> cv(2, vector<int>(n));
    vector<vector<int>> tmp(d);

    vector<int> sm(3);

    for (int i = 2; i < n; i++) {
        if (b[i] == 0 || a[i] == 0) {
            return 0;
        }

        if (abs(a[i] - b[i]) > d) {
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
            return 0;
        }
        if (tmp[i].size() == 1) {
            continue;
        }
        if (tmp[i][1] == 0) {
            return 0;
        }
        vector<int> cur;
        int cc = 0;
        for (int j = 1; j < tmp[i].size(); j++) {
            if (tmp[i][j] != tmp[i][j - 1] && tmp[i][j] - 1 != tmp[i][j - 1]) {
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

    return ans;
}

int solve() {
    int ans = 1;
    int dist = a[0] + b[0];
    vector<map<int, int>> mp(dist + 1);

    if (a[0] != b[1] || a[1] != b[0] || a[0] != 0) goto bad;
    for (int i = 0; i < n; i++) {
        if ((a[i] + b[i] - dist) % 2) goto bad;
        if ((a[i] - b[i] + dist) % 2) goto bad;

        int pos = (a[i] - b[i] + dist) / 2;
        int dep = (a[i] + b[i] - dist) / 2;

        if (pos < 0 || pos > dist) goto bad;
        if (dep < 0) goto bad;

        mp[pos][dep]++;
    }

    for (int i = 0; i <= dist; i++) {
        if (mp[i][0] != 1) goto bad;
        for (auto x : mp[i]) {
            if (x.f != 0 && mp[i][x.f - 1] == 0) goto bad;
        }
    }

    for (int i = 0; i <= dist; i++) {
        for (auto x : mp[i]) {
            if (x.f == 0) continue;
            ans *= binexp(mp[i][x.f - 1], x.s), ans %= MOD;
        }
    }

    return ans;
bad:
    return 0;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    n = 4;
    for (int i1 = 0; i1 < 5; i1++) {
        for (int i2 = 0; i2 < 5; i2++) {
            for (int i3 = 0; i3 < 5; i3++) {
                for (int i4 = 0; i4 < 5; i4++) {
                    for (int j1 = 0; j1 < 5; j1++) {
                        for (int j2 = 0; j2 < 5; j2++) {
                            for (int j3 = 0; j3 < 5; j3++) {
                                for (int j4 = 0; j4 < 5; j4++) {
                                    a = {i1, i2, i3, i4};
                                    b = {j1, j2, j3, j4};
                                    for (auto x : a) cout << x << ' ';
                                    cout << '\n';
                                    for (auto x : b) cout << x << ' ';
                                    cout << '\n';
                                    int a1 = solve(), a2 = check();
                                    if (a1 != a2) {
                                        cout << "ohno\n";
                                        cout << a1 << ' ' << a2 << '\n';
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // int t = 1;
    // cin >> t;
    // while (t--) solve();
}