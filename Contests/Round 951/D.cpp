// Codeforces Round 951: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;

bool test(string a, int p) {
    string b = a.substr(0, p);
    reverse(b.begin(), b.end());
    string c = a.substr(p, n - p) + b;
    // cout << c << '\n';
    for (int i = 0; i < k - 1; i++) {
        if (c[i] != c[i + 1]) return false;
    }
    for (int i = k; i < n; i++) {
        if (c[i - k] == c[i]) return false;
    }
    return true;
}

void solve() {
    string a;
    cin >> n >> k >> a;
    int p = n - k - 1;
    while (p >= 0 && a[p] != a[p + k]) p--;
    // cout << p << ' ';
    if (p == -1) {
        p = 0;
        while (p < n - 1 && a[p] == a[p + 1]) p++;
        p++;
        if (p == k) p = n;
        // cout << p << ' ';
        cout << (test(a, p) ? p : -1) << '\n';
        return;
    }
    if (a[p] != a[p + 1]) {
        p++;
        while (a[p] == a[p + 1]) p++;
    }
    p++;
    // cout << p << ' ';
    cout << (test(a, p) ? p : -1) << '\n';
    // vector<int> ds(1, 0);
    // vector<pair<int, int>> bs;
    // for (int i = 1; i < n; i++) {
    //     if (a[i - 1] != a[i]) ds.push_back(i);
    // }
    // ds.push_back(n);
    // for (int i = 1; i < (int)ds.size(); i++) {
    //     bs.push_back({ds[i] - ds[i - 1], ds[i]});
    // }
    // vector<pair<int,int>> bad;
    // for (int i = 1; i < (int)bs.size() - 1; i++) {
    //     if (bs[i].f != k) bad.push_back({bs[i].s});
    // }
    // if ((int)bad.size() > 1) {
    //     cout << "-1\n";
    //     return;
    // }
    // int p;
    // if ((int)bad.size() == 0) {
    //     p = (bs[0] == k ? n : bs[0] - 1);
    // } else {
    //     p = bad[0];
    // }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}