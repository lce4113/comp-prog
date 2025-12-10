// CSES Sliding Window Problems: Sliding Window Distinct Values

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> c;
    for (int i = 0; i < k; i++) c[a[i]]++;
    cout << c.size() << ' ';
    for (int l = 0, r = k; r < n; l++, r++) {
        c[a[l]]--;
        c[a[r]]++;
        if (c[a[l]] == 0) c.erase(a[l]);
        cout << c.size() << ' ';
    }
    cout << '\n';
}