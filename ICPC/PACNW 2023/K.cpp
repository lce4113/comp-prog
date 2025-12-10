// ICPC Pacific Northwest 2023: Problem K

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int c = 0;
const int MAXN = 1e5;
set<int> rem({MAXN + 1});

void calc() {
    if (c == MAXN) {
        cout << c / 3 * 2 + 2 << endl;
        return;
    }
    if (c % 3 == 0) {
        cout << c / 3 * 2 + 1 << endl;
        return;
    }
    if (c % 3 == 1 && rem.count(c + 1)) {
        cout << c / 3 * 2 + 2 << endl;
        return;
    }
    if (c % 3 == 2 && rem.count(c - 1)) {
        cout << c / 3 * 2 + 2 << endl;
        return;
    }
    cout << -1 << endl;
    rem.insert(c);
}

void res() {
    for (int i = 0; i <= MAXN; i++) {
        if (i != MAXN && i % 3 == 1 && !rem.count(i) && !rem.count(i + 1)) i++;
        if (!rem.count(i)) cout << i << ' ';
    }
    cout << endl;
}

void solve() {
    cout << (MAXN + 1) - (MAXN + 1) / 3 << endl;
    cin >> c;
    while (c != -1) {
        calc();
        cin >> c;
    }
    res();
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}