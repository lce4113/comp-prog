// CSES Mathematics: System of Linear Equations

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

void solve(vector<vector<int>> A, vector<int> b, vector<int> &x) {
    int n = A.size(), m = x.size(), rank = 0, br, bc;
    vector<int> col(m);
    iota(col.begin(), col.end(), 0);
    for (int i = 0; i < n; i++) {
        int v, bv = 0;
        for (int r = i; r < n; r++) {
            for (int c = i; c < m; c++) {
                if ((v = A[r][c]) > bv) {
                    br = r, bc = c, bv = v;
                }
            }
        }
        if (bv == 0) break;
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        for (int j = 0; j < n; j++) {
            swap(A[j][i], A[j][bc]);
        }
        bv = binexp(A[i][i]);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int fac = A[j][i] * bv % MOD;
            b[j] = (b[j] - fac * b[i] % MOD + MOD) % MOD;
            for (int k = 0; k < m; k++) {
                A[j][k] = (A[j][k] - fac * A[i][k] % MOD + MOD) % MOD;
            }
        }
        rank++;
    }
    for (int i = 0; i < rank; i++) {
        x[col[i]] = b[i] * binexp(A[i][i]) % MOD;
    }
}

bool check(vector<vector<int>> &A, vector<int> &b, vector<int> &x) {
    int n = A.size(), m = x.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i] = (b[i] - A[i][j] * x[j] % MOD + MOD) % MOD;
        }
    }
    return reduce(b.begin(), b.end()) == 0;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    vector<int> b(n), x(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    solve(A, b, x);
    if (x[0] == -1 || !check(A, b, x)) {
        cout << "-1\n";
        return 0;
    }
    for (auto y : x) cout << y << ' ';
    cout << '\n';
}