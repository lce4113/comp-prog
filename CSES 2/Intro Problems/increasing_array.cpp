// CSES Introductory Problems: Increasing Array

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mx = -1, ans = 0;
    for (int i = 0; i < n; i++) {
        mx = max(a[i], mx);
        ans += mx - a[i];
    }
    cout << ans << '\n';
}