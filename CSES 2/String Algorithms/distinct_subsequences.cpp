// CSES String Algorithms: Distinct Subsequences

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin >> a;
    int n = a.size();
    vector<int> nxt(n, n);
    vector<int> lst(26, n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = lst[a[i] - 'a'];
        lst[a[i] - 'a'] = i;
    }
    vector<int> pfs(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int c;
        if (nxt[i] == n) {
            c = pfs[i + 1] + 1;
        } else {
            c = pfs[i + 1] - pfs[nxt[i] + 1] + MOD;
        }
        c %= MOD;
        pfs[i] = pfs[i + 1] + c;
        pfs[i] %= MOD;
    }
    cout << pfs[0] << '\n';
}