// Codeforces Round 1025: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int q(string a) {
    cout << a << endl;
    int n;
    cin >> n;
    return n;
}

void solve() {
    int n;
    cin >> n;

    q("mul 999999999");
    q("digit");
    if (n != 81) q("add " + to_string(n - 81));
    q("!");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}