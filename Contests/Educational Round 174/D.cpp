// Codeforces Educational Round 174
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

bool pal(string a) {
    int n = a.size();
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) return false;
    }
    return true;
}

int ch(string a) {
    int n = a.size();
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);

    int r = -1;
    for (auto x : mp) {
        int N = x.s.size();
        for (int i = N / 2 - 1, j = N / 2; i >= 0; i--, j++) {
            // cout << x.f << ' ' << x.s[i] << ' ' << x.s[j] << '\n';
            if (x.s[i] + x.s[j] != n - 1) {
                r = max(r, x.s[i]);
                break;
            }
        }
    }

    // cout << r.f << ' ' << r.s << '\n';
    // cout << r << ' ';
    return r + 1;
}

void solve() {
    string a;
    cin >> a;
    // cout << a << ' ';

    if (pal(a)) {
        cout << "0\n";
        return;
    }

    int n = a.size(), l = 0;
    while (a[l] == a[n - 1 - l]) l++;
    n -= 2 * l;
    a = a.substr(l, n);

    int ans = ch(a);
    reverse(a.begin(), a.end());
    ans = min(ans, ch(a));
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}