// Problem A

#include <bits/stdc++.h>
using namespace std;

const int N = 105;

string a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
        if (a[i].size() <= a[i - 1].size()) {
            string t = "";
            string tt = "1";
            for (int j = 0; j < int(a[i - 1].size()); j++) t += "9";
            for (int j = 1; j < int(a[i - 1].size()); j++) tt += "0";
            // cout << tt << endl;
            if (a[i - 1] == t || a[i - 1] == tt) continue;
            // cout << a[i - 1] << endl;
            for (int j = 0; j < n; j++) {
                if (j != i - 1)
                    cout << a[j] << " ";
                else {
                    for (int k = 0; k < int(a[i - 1].size()); k++)
                        if ((a[i - 1][k] - '0') <= (a[i][k] - '0') &&
                            (a[i - 1][k] != '1' || k != 0) &&
                            a[i - 1][k] != '0') {
                            char ts = ((a[i - 1][k] - '0') - 1 + '0');
                            a[i][k] = ts;
                            break;
                        }
                    cout << a[i - 1] << " ";
                }
            }
            cout << endl;
            return;
        }
    puts("impossible");
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}