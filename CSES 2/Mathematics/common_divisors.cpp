// CSES Mathematics: Common Divisors

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
vector<int> nums(MAXN + 1);

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        nums[x]++;
    }
    for (int i = MAXN; i >= 1; i--) {
        int c = 0;
        for (int j = i; j <= MAXN; j += i) {
            c += nums[j];
        }
        if (c > 1) {
            cout << i << '\n';
            return 0;
        }
    }
}
