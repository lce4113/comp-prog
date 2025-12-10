// CSES Tree Algorithms: Company Queries I

#include <bits/stdc++.h>
using namespace std;

const int MAXB = 20;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> bin(MAXB + 1, vector<int>(n, -2));
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        bin[0][i] = x;
    }

    for (int i = 1; i <= MAXB; i++) {
        for (int j = 0; j < n; j++)
            bin[i][j] = bin[i - 1][j] == -2 ? -2 : bin[i - 1][bin[i - 1][j]];
    }

    while (q--) {
        int v, k;
        cin >> v >> k;
        v--;
        for (int i = 0; k; i++, k /= 2) {
            if (k & 1) v = bin[i][v];
            if (v == -2) break;
        }
        cout << v + 1 << '\n';
    }
}