// CSES Intro Problems: Palindrome Reorder

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    string ans = a;
    for (auto &x : mp) {
        if ((x.s % 2) && (n % 2)) {
            x.s--;
            ans[n / 2] = x.f;
            break;
        }
    }
    int i = 0, j = n - 1;
    for (auto x : mp) {
        if (x.s % 2) {
            cout << "NO SOLUTION\n";
            return;
        }
        for (; x.s; x.s -= 2, i++, j--) {
            ans[i] = x.f, ans[j] = x.f;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
