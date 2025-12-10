// Problem M

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a;
    cin >> b;
    if (a == "0" || b == "0") {
        cout << "0" << endl;
        return;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] == 'S') cnt1++;
    for (int i = 0; i < (int)b.size(); i++)
        if (b[i] == 'S') cnt2++;

    string ans = "";
    int cnt = cnt1 * cnt2;
    for (int i = 0; i < cnt; i++) ans += "S(";
    ans += "0";
    for (int i = 0; i < cnt; i++) ans += ")";
    cout << ans << endl;
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}