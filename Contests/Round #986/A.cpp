// Codeforces Round #986: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string str;
    cin >> str;
    pair<int, int> tot = {0, 0};
    for (int i = 0; i < n; i++) {
        if (str[i] == 'N') {
            tot.s++;
        } else if (str[i] == 'E') {
            tot.f++;
        } else if (str[i] == 'S') {
            tot.s--;
        } else if (str[i] == 'W') {
            tot.f--;
        }
        if (tot.f == a && tot.s == b) {
            cout << "YES\n";
            return;
        }
    }
    if (tot.f == 0 && tot.s == 0) {
        cout << "NO\n";
        return;
    }
    pair<int, int> curr = {0, 0};
    for (int i = 0; abs(curr.f) <= 20 && abs(curr.s) <= 20; i = (i + 1) % n) {
        if (str[i] == 'N') {
            curr.s++;
        } else if (str[i] == 'E') {
            curr.f++;
        } else if (str[i] == 'S') {
            curr.s--;
        } else if (str[i] == 'W') {
            curr.f--;
        }
        if (curr.f == a && curr.s == b) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
