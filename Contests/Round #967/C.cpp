// Codeforces Round #967: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void res(vector<int> ans) {
    cout << "! ";
    for (int i = 2; i < (int)ans.size(); i++) cout << ans[i] << ' ' << i << ' ';
    cout << endl;
}

int q(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int n;
    cin >> n;
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n + 1, -1);
    for (int i = 2; i <= n; i++) {
        int start = i, prev = 1, next = 1;
        while (next != start) {
            prev = next;
            next = q(start, next);
        }
        ans[start] = prev;
    }
    res(ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}