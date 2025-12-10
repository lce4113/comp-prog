// CSES Additional Problems II: Book Shop II

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, tot;
    cin >> n >> tot;
    vector<array<int, 4>> books(n);
    for (auto &x : books) cin >> x[1];
    for (auto &x : books) cin >> x[2];
    for (auto &x : books) cin >> x[3];
}