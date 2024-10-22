// CodeForces Round #973: Problem C

#include <bits/stdc++.h>
using namespace std;

bool query(string s) {
    cout << "? " << s << '\n';
    cout.flush();
    int res;
    cin >> res;
    return (res == 1);
}

void solve() {
    int n;
    cin >> n;
    string ans = "";
    if (query("1")) {
        ans += '1';
    } else {
        ans += '0';
    }
    while ((int)ans.size() < n) {
        bool one = query(ans + '1');
        bool zero = query(ans + '0');
        if (one) {
            ans += '1';
        } else if (zero) {
            ans += '0';
        } else {
            break;
        }
    }
    while ((int)ans.size() < n) {
        bool one = query('1' + ans);
        // bool zero = query('0' + ans);
        if (one) {
            ans = '1' + ans;
        } else {
            ans = '0' + ans;
        }
    }
    cout << "! " << ans << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}