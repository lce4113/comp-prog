// Codeforces Round 1039: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    string ans;
    for (int l = 0, r = n - 1, p = 0; l <= r; p ^= 1) {
        if (p) {
            if (a[l] < a[r]) {
                ans += 'L', l++;
            } else {
                ans += 'R', r--;
            }
        } else {
            if (a[l] > a[r]) {
                ans += 'L', l++;
            } else {
                ans += 'R', r--;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}