// Codeforces Round 985: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 4e5;
vector<bool> prime(MAXN + 1, true);

bool check(vector<int> a, int ans) {
    if (ans == -1) {
        for (int i = 2; i <= a[0]; i++) {
            if (check(a, i)) {
                cout << i << '\n';
                return false;
            }
        }
        return true;
    }
    set<int> A;
    for (auto x : a) A.insert(x);
    vector<bool> vis(MAXN + 1, false);
    queue<int> Q;
    Q.push(ans);
    vis[ans] = true;
    A.erase(ans);
    while (Q.size()) {
        int curr = Q.front();
        Q.pop();
        // cout << curr << '\n';
        for (int f = 1; f * f <= curr; f++) {
            if (curr % f == 0) {
                int nxt1 = curr + f, nxt2 = curr + curr / f;
                if (f != 1 && nxt1 <= MAXN && !vis[nxt1]) {
                    Q.push(nxt1);
                    vis[nxt1] = true;
                    A.erase(nxt1);
                    if (A.empty()) return true;
                }
                if (nxt2 <= MAXN && !vis[nxt2]) {
                    Q.push(nxt2);
                    vis[nxt2] = true;
                    A.erase(nxt2);
                    if (A.empty()) return true;
                }
            }
        }
    }
    return false;
}

// int solve(vector<int> a) {
void solve() {
    // int n = a.size();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (prime[a[i]]) {
            cout << "-1\n";
            return;
            // return -1;
        }
    }
    if (!prime[a[0]]) {
        cout << "2" << '\n';
        return;
        // return 2;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] % 2) {
            for (int f = 2; f * f <= a[i]; f++) {
                if (a[i] % f == 0) {
                    a[i] -= f;
                    break;
                }
            }
        }
        if (a[i] < 2 * a[0]) {
            cout << "-1\n";
            return;
            // return -1;
        }
    }
    cout << a[0] << '\n';
    // return a[0];
}

int32_t main() {
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= MAXN; i += p) prime[i] = false;
        }
    }

    // for (int i1 = 2; i1 <= 11; i1++) {
    //     if (!prime[i1]) continue;
    //     for (int i2 = i1 + 1; i2 <= 50; i2++) {
    //         vector<int> a = {i1, i2};
    //         int ans = solve(a);
    //         int c = check(a, ans);
    //         for (auto x : a) cout << x << ' ';
    //         cout << ans << '\n';
    //         if (!c) {
    //             cout << "ohno\n";
    //             return 0;
    //         }
    //     }
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}