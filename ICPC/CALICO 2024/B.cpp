// CALICO 2024: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    map<char, char> mp;
    mp['N'] = 'C';
    mp['U'] = 'C';
    mp['H'] = 'I';
    map<char, int> cnt;
    for (auto x : a) {
        if (!mp.count(x))
            cnt[x]++;
        else
            cnt[mp[x]]++;
    }
    // for (auto x : cnt) cout << x.f << ' ' << x.s << '\n';
    map<char, int> c;
    c['C'] = 2;
    c['A'] = 1;
    c['L'] = 1;
    c['I'] = 1;
    c['O'] = 1;
    int ans = -1;
    for (auto x : cnt) {
        // cout << x.f << '\n';
        if (!c.count(x.f)) {
            cout << "-1\n";
            return;
        }
        ans = max(ans, (int)ceil((double)x.s / c[x.f]));
    }
    cout << ans << '\n';
    // CALICO
    // C 2, A 1, L 1, I 1, O 1
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}