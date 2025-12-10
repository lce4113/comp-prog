// Codeforces Educational Round 178: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    if (a[0] == a.back()) {
        cout << (a[0] == 'A' ? "Alice\n" : "Bob\n");
        return;
    }
    if (a[0] == 'B') {
        if (a[n - 2] == a[0]) {
            cout << (a[0] == 'A' ? "Alice\n" : "Bob\n");
        } else {
            cout << (a.back() == 'A' ? "Alice\n" : "Bob\n");
        }
        return;
    }
    if (mp['B'] == 1) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}