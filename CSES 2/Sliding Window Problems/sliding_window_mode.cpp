// CSES Sliding Window Problems: Sliding Window Mode

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    set<pair<int, int>> c;
    map<int, int> store;
    for (int i = 0; i < k; i++) store[a[i]]++;
    for (auto x : store) c.insert({-x.s, x.f});
    cout << c.begin()->s << ' ';
    for (int l = 0, r = k; r < n; l++, r++) {
        c.erase({-store[a[l]], a[l]});
        store[a[l]]--;
        c.insert({-store[a[l]], a[l]});
        c.erase({-store[a[r]], a[r]});
        store[a[r]]++;
        c.insert({-store[a[r]], a[r]});
        cout << c.begin()->s << ' ';
    }
    cout << '\n';
}