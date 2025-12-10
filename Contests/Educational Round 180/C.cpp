// Codeforces Educational Round 180: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

// max( a[mxi]-b-c, abs(b-c) ) < a < b+c

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int mxi = n - 1;
            while (mxi == i || mxi == j) mxi--;
            int hi = a[i] + a[j] - 1;
            int lo = max(abs(a[i] - a[j]), a[mxi] - a[i] - a[j]) + 1;

            int end = --upper_bound(a.begin(), a.end(), hi) - a.begin();
            int start = lower_bound(a.begin(), a.end(), lo) - a.begin();
            int curr = max(0ll, end - start + 1);
            if (start <= i && i <= end) curr--;
            if (start <= j && j <= end) curr--;
            ans += curr;
            // cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << '\n';
            // cout << "lo,hi: " << lo << ' ' << hi << '\n';
            // cout << "start,end: " << start << ' ' << end << '\n';
            // cout << "contrib: " << curr << '\n';
            // cout << '\n';
        }
    }
    cout << ans / 3 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}