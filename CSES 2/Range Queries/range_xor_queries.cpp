// CSES Range Queries: Range Xor Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() ^ x);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (pfs[r] ^ pfs[l - 1]) << '\n';
    }
}