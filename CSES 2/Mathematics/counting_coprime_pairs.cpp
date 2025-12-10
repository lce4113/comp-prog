// CSES Mathematics: Counting Coprime Pairs

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6;
vector<int> nums(MAXN + 1);
vector<int> lp(MAXN + 1), pr;

int P(int n) {
    set<int> res;
    while (n != 1) {
        if (res.count(lp[n])) return -1;
        res.insert(lp[n]), n /= lp[n];
    }
    return res.size();
}

int32_t main() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    int n;
    cin >> n;
    int ans = n * (n - 1) / 2;
    while (n--) {
        int x;
        cin >> x;
        nums[x]++;
    }
    for (int i = 2; i <= MAXN; i++) {
        if (P(i) == -1) continue;
        int cnt = 0;
        for (int j = i; j <= MAXN; j += i) cnt += nums[j];
        if (cnt <= 1) continue;
        ans -= cnt * (cnt - 1) / 2 * (P(i) % 2 ? 1 : -1);
    }
    cout << ans << '\n';
}