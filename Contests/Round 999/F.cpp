// Codeforces Round 999: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

string a, b;

void solve() {
    cin >> a >> b;
    int n = a.size();

    vector<int> oa, ob;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') oa.push_back(i);
        if (b[i] == '1') ob.push_back(i);
    }

    if (oa.size() != ob.size()) {
        cout << "-1\n";
        return;
    }
    if (oa.size() == 0) {
        cout << "0\n";
        return;
    }

    vector<array<int, 3>> op;
    op.push_back({oa[0], ob[0], 1});
    if (oa[0] > ob[0] && ob[0] != 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i < (int)oa.size(); i++) {
        // cout << oa[i] << ' ' << ob[i] << ' ' << op.back()[0] << ' '
        //      << op.back()[1] << ' ' << op.back()[2] << '\n';
        if (oa[i] == op.back()[0] + op.back()[2] &&
            ob[i] == op.back()[1] + op.back()[2]) {
            op.back()[2]++;
        } else if (oa[i] == op.back()[0] + op.back()[2]) {
            cout << "-1\n";
            return;
        } else if (op.back()[0] < op.back()[1] && oa[i] > ob[i]) {
            cout << "-1\n";
            return;
        } else if (op.back()[0] < op.back()[1] &&
                   ob[i] != op.back()[1] + op.back()[2]) {
            cout << "-1\n";
            return;
        } else if (op.back()[1] + op.back()[2] != ob[i] && oa[i] > ob[i]) {
            cout << "-1\n";
            return;
        } else {
            op.push_back({oa[i], ob[i], 1});
        }
    }
    if (op.back()[0] < op.back()[1] && op.back()[1] + op.back()[2] != n) {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (auto x : op) {
        if (x[0] != x[1]) ans++;
        // cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    }

    cout << ans << '\n';
}

int32_t main() {
    // for (char i1 = '0'; i1 != '2'; i1++) {
    //     for (char i2 = '0'; i2 != '2'; i2++) {
    //         for (char i3 = '0'; i3 != '2'; i3++) {
    //             for (char i4 = '0'; i4 != '2'; i4++) {
    //                 for (char i5 = '0'; i5 != '2'; i5++) {
    //                     for (char i6 = '0'; i6 != '2'; i6++) {
    //                         for (char i7 = '0'; i7 != '2'; i7++) {
    //                             for (char i8 = '0'; i8 != '2'; i8++) {
    //                                 if ((i1 == '1') + (i2 == '1') +
    //                                         (i3 == '1') + (i4 == '1') !=
    //                                     (i5 == '1') + (i6 == '1') +
    //                                         (i7 == '1') + (i8 == '1'))
    //                                     continue;
    //                                 a = "", a += i1, a += i2, a += i3, a +=
    //                                 i4; b = "", b += i5, b += i6, b += i7, b
    //                                 += i8; cout << a << '\n'; cout << b <<
    //                                 '\n'; solve();
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    int t = 1;
    cin >> t;
    while (t--) solve();
}