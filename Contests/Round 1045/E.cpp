// Codeforces Round 1045: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void q1(int x) { cout << "swap " << x + 1 << endl; }

int q2(int x) {
    cout << "throw " << x + 1 << endl;
    int n;
    cin >> n;
    return n;
}

void res(vector<int> &ans) {
    cout << "! ";
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n), thr(n + 1);
    ans[n - 1] = q2(n - 2) == 1 ? 2 : 1;
    q1(n - 2);
    thr[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (thr[i + 1] != thr[i + 2]) {
            thr[i] = q2(i);
            ans[i] = (thr[i] == thr[i + 1] + 1) ? 1 : 2;
        } else {
            thr[i] = thr[i + 1] + 1;
        }
    }
    for (int i = 0; i <= n - 2; i++) {
        if (ans[i]) continue;
        q1(i);
        thr[i + 1] = q2(i + 1);
        thr[i] = thr[i + ans[i + 1]] + 1;
        ans[i] = (thr[i + 1] == thr[i + 2] + 1) ? 1 : 2;
    }
    swap(ans[n - 1], ans[n - 2]);
    res(ans);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}