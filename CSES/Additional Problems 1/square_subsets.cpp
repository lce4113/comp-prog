// CSES Additional Problems I: Square Subsets

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 5e3;
vector<int> lp(MAXN + 1), pr;

bitset<MAXN> reduce(int n) {
    map<int, bool> P;
    while (n != 1) P[lp[n]] ^= 1, n /= lp[n];
    bitset<MAXN> res;
    int N = pr.size();
    for (int i = 0; i < N; i++) res[i] = P[pr[i]];
    return res;
}

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<bool> has(MAXN, 0);
    vector<bitset<MAXN>> b(MAXN);
    for (auto v : a) {
        auto c = reduce(v);
        for (int i = 0; i < MAXN; i++) {
            if (!c[i]) continue;
            if (!has[i]) {
                b[i] = c;
                has[i] = 1;
                break;
            }
            c ^= b[i];
        }
    }
    int bs = 0;
    for (auto x : b) bs += x != 0;
    cout << binexp(2, n - bs) << '\n';
}