// CSES Bitwise Operations: XOR Pyramid Diagonal

#include <bits/stdc++.h>
using namespace std;

const int B = 20;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n);
    for (auto &x : dp) cin >> x;
    for (int j = 0; j < B; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if ((1 << j) & i) dp[i] ^= dp[i ^ (1 << j)];
        }
    }
    for (auto x : dp) cout << x << ' ';
    cout << '\n';
}