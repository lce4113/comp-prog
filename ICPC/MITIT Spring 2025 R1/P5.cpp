// MITIT Spring 2025: Problem 5

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void q(vector<int> a) {
    cout << a.size() << ' ';
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

void rec(bool first) {
    string a;
    cin >> a;
    int n = a.size();
    int l = 0, r = n - 1;
    while (a[l] == '0') l++;
    while (a[r] == '1') r--;
    if (r < l) {
        if (first) cout << "Second" << endl;
        return;
    }
    l++, r--;
    while (a[l] == '0' && a[r] == '1') l++, r--;
    if (r < l) {
        cout << "Second" << endl;
        rec(0);
        return;
    }
    if (first) cout << "First" << endl;
    int os = 0;
    for (auto x : a) os += x == '1';
    l = n - os - 1, r = n - os;
    while (a[l] == '0' && a[r] == '1') l--, r++;
    vector<int> ans;
    // cout << l << ' ' << r << '\n';
    if (a[l] == '0' && a[r] == '0') {
        for (int i = 1; i <= n; i++) {
            if (i - 1 > l && i - 1 <= r) continue;
            ans.push_back(i);
        }
    } else if (a[l] == '1' && a[r] == '1') {
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= l && i - 1 < r) continue;
            ans.push_back(i);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= l && i - 1 <= r) continue;
            ans.push_back(i);
        }
    }
    q(ans);
    rec(0);
}

void solve() { rec(1); }

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
