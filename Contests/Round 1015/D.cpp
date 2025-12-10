// Codeforces Round 1015: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    set<int> rem;
    for (int i = 0; i < n; i++) rem.insert(i);
    // int mex1 = -1;
    for (int i = 0; rem.size(); i++) {
        int cnt = 0;
        for (int j = *rem.begin(); j < n && cnt <= m; j += k, cnt++) {
            a[j] = i;
            rem.erase(j);
        }
        // if (cnt != m + 1 && mex1 == -1) mex1 = i;
    }

    vector<int> A(n);
    int i = 0;
    for (int c = 0; i < n; i++, c++) {
        if (c >= n / (m + 1)) c = 0;
        A[i] = c;
    }
    // int mex2 = A.back();

    if (n / (m + 1) >= k) {
        for (auto x : A) cout << x << ' ';
        cout << '\n';
    } else {
        for (auto x : a) cout << x << ' ';
        cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}