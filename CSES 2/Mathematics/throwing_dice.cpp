// CSES Mathematics: Throwing Dice

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

vector<vector<int>> mat_mul(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += A[i][k] * B[k][j], res[i][j] %= MOD;
            }
        }
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0},
    };
    vector<vector<int>> res = {
        {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1},
    };
    for (; n; n /= 2, mat = mat_mul(mat, mat)) {
        if (n % 2) res = mat_mul(mat, res);
        // for (auto x : res) {
        //     for (auto y : x) cout << y << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    cout << res[0][0] << '\n';
}