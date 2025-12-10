// CALICO 2024: Problem F

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

vector<int> pfs(1, 0);

set<int> primeFactors(int n) {
    set<int> factors;

    // Check for divisibility by 2
    while (n % 2 == 0) {
        factors.insert(2);
        n /= 2;
    }

    // Check for divisibility by odd numbers starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.insert(n);
    }

    return factors;
}

int phi(int n) {
    int ans = n;
    for (auto x : primeFactors(n)) {
        ans /= x, ans *= x - 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    // cout << n << '\n';
    int i = --lower_bound(pfs.begin(), pfs.end(), n) - pfs.begin();
    n -= pfs[i];

    i += 2;
    // cout << i << ' ' << n << '\n';

    int x = 0;
    for (int k = 0; k < n; k++) {
        x++;
        while (gcd(x, i) != 1) {
            x++;
        }
        // cout << x << ' ' << i << '\n';
    }
    cout << x << ' ' << i - x << '\n';
}

int32_t main() {
    for (int i = 2; pfs.back() < 1e9 + 10; i++) {
        pfs.push_back(pfs.back() + phi(i));
    }
    // for (int i = 0; i < 100; i++) cout << pfs[i] << ' ';
    // cout << '\n';
    int t = 1;
    cin >> t;
    while (t--) solve();
}