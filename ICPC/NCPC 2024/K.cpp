#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, p;
    cin >> n >> p;
    n -= p;
    n %= 2 * p;
    if (n == p) n -= p;
    cout << n << '\n';
}