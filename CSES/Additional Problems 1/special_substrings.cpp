// CSES Additional Problems I: Special Substrings

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin >> a;
    int n = a.size();
    int N = 0;
    map<char, int> cs;
    for (auto c : a) {
        if (!cs.count(c)) cs[c] = N++;
    }
    map<vector<int>, int> mp;
    vector<int> cur(N - 1);
    int ans = 0;
    mp[cur]++;
    for (int i = 0; i < n; i++) {
        if (cs[a[i]] == 0) {
            for (auto &x : cur) x--;
        } else {
            cur[cs[a[i]] - 1]++;
        }
        ans += mp[cur];
        mp[cur]++;
    }
    cout << ans << '\n';
}