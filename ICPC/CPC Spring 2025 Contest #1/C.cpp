// Columbia Programming Camp
// Spring 2025 Contest #1
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int lg(int n) {
    int res = 1;
    while (n /= 2) res++;
    return res;
}

void solve() {
    int n;
    cin >> n;
    // cout << lg(n) << '\n';
    int N = lg(n);
    vector<int> ans;
    for (int i = 1; i < N; i++) ans.push_back(i);
    vector<int> bin;
    while (n) bin.push_back(n % 2), n /= 2;
    reverse(bin.begin(), bin.end());
    n /= 2;
    for (int i = N - 1, j = 1; i >= 1; i--, j++) {
        if (bin[j]) ans.push_back(i);
        n /= 2;
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}