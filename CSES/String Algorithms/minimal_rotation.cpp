// CSES String Algorithms: Minimal Rotation

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int P = 53;
const int MAXN = 1e6;

vector<int> pfs(1, 0), ps(MAXN + 1, 1);

int n;
string A;

int H(int h, int v) { return (h * P + v) % MOD; }
int hi(int l, int r) { return (pfs[r] - pfs[l] * ps[r - l] % MOD + MOD) % MOD; }

bool comp(int x, int y) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (hi(x, x + m) == hi(y, y + m)) {
            l = m;
        } else {
            r = m;
        }
    }
    // cout << l << '\n';
    if (l == n) return 1;
    return A[x + l] < A[y + l];
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) ps[i] = ps[i - 1] * P % MOD;

    cin >> A;
    n = A.size();
    A.insert(A.end(), A.begin(), A.end());

    for (auto c : A) pfs.push_back(H(pfs.back(), c - 'a'));

    int best = 0;
    for (int i = 1; i < n; i++) {
        if (comp(i, best)) best = i;
    }

    cout << A.substr(best, n) << '\n';
}