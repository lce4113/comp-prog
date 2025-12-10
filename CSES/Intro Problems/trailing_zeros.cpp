// CSES Intro Problems: Trailing Zeros

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) n /= 5, ans += n;
    cout << ans << '\n';
}
