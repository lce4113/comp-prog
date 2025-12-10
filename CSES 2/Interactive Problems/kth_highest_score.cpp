// CSES Interactive Problems: K-th Highest Score

#include <bits/stdc++.h>
using namespace std;

int n, k;

int q(char tp, int p) {
    if (p == 0) return 1e9 + 1;
    if (p == n + 1) return -1;
    cout << tp << ' ' << p << endl;
    int x;
    cin >> x;
    return x;
}

void res(int ans) {
    cout << "! " << ans << endl;
    exit(1);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    int l = max(0, k - n), r = min(n + 1, k + 1);
    while (r - l > 1) {
        int m = (l + r) / 2, mv = q('F', m);
        int M = q('S', k - m);
        if (M > mv) {
            int R = q('S', k - m + 1);
            if (R > mv) {
                r = m;
            } else {
                l = m;
            }
        } else {
            int mr = q('F', m + 1);
            if (mr > M) {
                l = m + 1;
            } else {
                l = m;
            }
        }
    }
    int mv = q('F', l);
    int M = q('S', k - l);
    res(min(M, mv));
}