// Codeforces Round 1067: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<pair<int, int>> conv(string &a) {
    int n = a.size();
    vector<pair<int, int>> res;
    while (1) {
        vector<int> c;
        for (int i = 0; i < n;) {
            int st = i;
            while (i < n && a[i] == a[st]) i++;
            c.push_back(i - st);
        }
        if (c.size() == 1 && c[0] == a.size() && a[0] == '0') break;
        if (c[0] > 1) {
            for (int i = 0; i < c[0]; i++) {
                a[i] = a[i] == '0' ? '1' : '0';
            }
            res.push_back({0, c[0] - 1});
            continue;
        }
        if (c[1] > 1) {
            for (int i = c[0]; i < c[0] + c[1]; i++) {
                a[i] = a[i] == '0' ? '1' : '0';
            }
            res.push_back({c[0], c[0] + c[1] - 1});
            continue;
        }
        if (c[2] > 1) {
            for (int i = c[0] + c[1]; i < c[0] + c[1] + c[2]; i++) {
                a[i] = a[i] == '0' ? '1' : '0';
            }
            res.push_back({c[0] + c[1], c[0] + c[1] + c[2] - 1});
            continue;
        }
        a[0] = a[0] == '0' ? '1' : '0';
        a[1] = a[1] == '0' ? '1' : '0';
        a[2] = a[2] == '0' ? '1' : '0';
        res.push_back({0, 2});
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    auto a1 = conv(a);
    auto a2 = conv(b);
    reverse(a2.begin(), a2.end());
    cout << a1.size() + a2.size() << '\n';
    for (auto x : a1) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
    for (auto x : a2) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}