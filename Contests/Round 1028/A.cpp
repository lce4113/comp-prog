#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    vector<int> a(4);
    for (auto &x : a) cin >> x;
    auto x = *min_element(a.begin(), a.end());
    if (x == a[1] || x == a[3]) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}