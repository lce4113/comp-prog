// CSES Graph Algorithms: Planets Queries I

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXB = 35;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    int bin[n][MAXB];
    for (int i = 0; i < n; i++) {
        cin >> bin[i][0];
        bin[i][0]--;
    }
    for (int i = 1; i < MAXB; i++) {
        for (int j = 0; j < n; j++) {
            bin[j][i] = bin[bin[j][i - 1]][i - 1];
        }
    }
    while (q--) {
        int u, k;
        cin >> u >> k;
        u--;
        for (int i = 0; i < MAXB; i++, k /= 2) {
            if (k % 2) u = bin[u][i];
        }
        cout << u + 1 << '\n';
    }
}
