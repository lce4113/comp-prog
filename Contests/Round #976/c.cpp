#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<bool> bin(int n) {
    vector<bool> ans;
    while (n > 0) {
        ans.push_back(n % 2);
        n /= 2;
    }
    return ans;
}

void solve() {
    int b, c, d;
    cin >> b >> c >> d;
    vector<bool> B = bin(b), C = bin(c), D = bin(d);
    int n = max({B.size(), C.size(), D.size()});
    while ((int)B.size() < n) B.push_back(0);
    while ((int)C.size() < n) C.push_back(0);
    while ((int)D.size() < n) D.push_back(0);
    int ans = 0;
    for (int i = 0, mult = 1; i < n; i++, mult *= 2) {
        // cout << D[i] << ' ' << C[i] << ' ' << B[i] << '\n';
        if (D[i] && C[i] && B[i]) {
            continue;
        } else if (!D[i] && C[i] && B[i]) {
            ans += mult;
        } else if (D[i] && !C[i] && B[i]) {
            continue;
        } else if (!D[i] && !C[i] && B[i]) {
            cout << "-1\n";
            return;
        } else if (D[i] && C[i] && !B[i]) {
            cout << "-1\n";
            return;
        } else if (!D[i] && C[i] && !B[i]) {
            continue;
        } else if (D[i] && !C[i] && !B[i]) {
            ans += mult;
        } else if (!D[i] && !C[i] && !B[i]) {
            continue;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}