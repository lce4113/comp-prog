// Codeforces Round 1015: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), A(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    for (auto &x : b) {
        cin >> x;
        x--;
    }

    for (int i = 0; i < n; i++) A[a[i]] = b[i];

    int os = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == i) {
            os++;
        } else if (A[A[i]] != i) {
            cout << "-1\n";
            return;
        }
    }

    if (os != n % 2) {
        cout << "-1\n";
        return;
    }

    vector<int> ap(n);
    for (int i = 0; i < n; i++) ap[a[i]] = i;

    vector<pair<int, int>> ans;
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (a[i] == b[i]) {
            if (n / 2 == i) continue;
            ans.push_back({n / 2, i});
            int x = a[n / 2], y = a[i];
            swap(a[n / 2], a[i]), swap(b[n / 2], b[i]);
            swap(ap[x], ap[y]);
        }
        if (ap[b[i]] == n - i - 1) continue;
        int x = a[n - i - 1], y = b[i];
        ans.push_back({ap[b[i]], n - i - 1});
        swap(a[ap[b[i]]], a[n - i - 1]), swap(b[ap[b[i]]], b[n - i - 1]);
        swap(ap[x], ap[y]);
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}