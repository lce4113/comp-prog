// CSES Bitwise Operations: SOS Bit Problem

#include <bits/stdc++.h>
using namespace std;

const int B = 20;
const int MAXN = 1 << (B + 1);
int sub[MAXN + 1];
int sup[MAXN + 1];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (auto x : a) sub[x]++, sup[x]++;

    for (int j = 1; j <= B; j++) {
        for (int i = 1; i <= MAXN; i++) {
            int e = 1 << (j - 1);
            if (i & e) sub[i] += sub[i ^ e];
            if ((i & e) == 0 && (i ^ e) <= MAXN) sup[i] += sup[i ^ e];
        }
    }

    for (auto x : a)
        cout << sub[x] << ' ' << sup[x] << ' ' << n - sub[x ^ ((1 << B) - 1)]
             << '\n';
}