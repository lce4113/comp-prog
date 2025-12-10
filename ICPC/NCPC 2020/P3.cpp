// Problem C

#include <bits/stdc++.h>

#define x first
#define y second
using namespace std;

const int N = 1005;

typedef pair<int, int> pii;

int a[N];
vector<pii> b;
vector<pii> ans;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    if (cnt % 2 == 1) {
        puts("no");
        return;
    }

    int idx1 = 0, idx2 = n - 1;
    while (idx1 < idx2) {
        if (b[idx2].x <= 0) {
            idx2--;
            continue;
        }
        if (b[idx1].x <= 0) {
            idx1++;
            continue;
        }
        if (b[idx2] < b[idx2 - 1]) {
            auto it = lower_bound(b.begin(), b.end(), b[idx2]);
            int idx = it - b.begin();
            // for (int i = 0; i < b.size(); i++) cout << b[i].x << " ";
            // cout << endl;
            // cout << idx << '\n';
            pii t = b[idx2];
            b[idx2] = b[idx];
            b[idx] = t;
            // for (int i = 0; i < b.size(); i++) cout << b[i].x << " ";
            // cout << endl;
            // cout << "!!" << endl;
        }
        b[idx1].x--;
        b[idx2].x--;
        ans.push_back({b[idx1].y, b[idx2].y});
    }

    if (b[idx2].x != 0) {
        puts("no");
        return;
    }
    puts("yes");
    for (int i = 0; i < (int)ans.size(); i++)
        cout << (ans[i].x + 1) << " " << (ans[i].y + 1) << endl;
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}