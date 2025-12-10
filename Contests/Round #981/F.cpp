#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

// map<int, int> pfac(int a) {
//     map<int, int> ans;
//     int n = a;
//     for (int i = 2; i * i <= a; i = i * 1) {
//         while (n % i == 0) n /= i, ans[i]++;
//     }
//     if (n > 1) ans[n]++;
//     return ans;
// }

int cycle(int n) {
    // map<int, int> pf = pfac(n);
    if (n == 1) return 1;
    vector<int> fib;
    fib.push_back(1), fib.push_back(1);
    while (fib.back() % n) {
        int curr = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(curr % n);
    }
    return fib.size();
}

void solve() {
    int n, k;
    cin >> n >> k;
    n %= MOD;
    cout << cycle(k) << '\n';
    n *= cycle(k);
    n %= MOD;
    cout << n << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}