// NEERC 2016-17: Problem I

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, n;
    cin >> n >> a >> b;
    vector<array<int, 3>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab[i][0];
        ab[i][2] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> ab[i][1];
    }
    sort(ab.rbegin(), ab.rend());

    priority_queue<pair<int, int>> Q;
    vector<int> right(n + 1), ri(n, -1);
    for (int i = n - 1; i >= a; i--) {
        Q.push({ab[i][1], ab[i][2]});
        if (i < a + b) {
            right[i] = right[i + 1] + Q.top().f;
            ri[i] = Q.top().s;
            Q.pop();
        }
    }

    while (Q.size()) Q.pop();

    int left = 0, ans = -1, ansp = -1;
    for (int i = 0; i < a; i++) {
        left += ab[i][0];
        Q.push({ab[i][1] - ab[i][0], ab[i][2]});
    }
    vector<int> li(n, -1);
    for (int i = a; i < a + b; i++) {
        if (left + right[i] > ans) {
            ans = left + right[i];
            ansp = i;
        }
        left += ab[i][0];
        Q.push({ab[i][1] - ab[i][0], ab[i][2]});
        left += Q.top().f;
        li[i] = Q.top().s;
        Q.pop();
    }
    if (left + right[a + b] > ans) {
        ans = left + right[a + b];
        ansp = a + b;
    }

    set<int> as, bs;
    for (int i = 0; i < ansp; i++) as.insert(ab[i][2]);
    for (int i = 0; i < ansp; i++) {
        if (li[i] == -1) continue;
        as.erase(li[i]);
        bs.insert(li[i]);
    }
    for (int i = ansp; i < n; i++) {
        if (ri[i] != -1) bs.insert(ri[i]);
    }

    // for (auto x : ab) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // cout << ansp << '\n';
    // cout << "ri: ";
    // for (auto x : ri) cout << x << ' ';
    // cout << '\n';
    // cout << "li: ";
    // for (auto x : li) cout << x << ' ';
    // cout << '\n';

    cout << ans << '\n';
    for (auto x : as) cout << x + 1 << ' ';
    cout << '\n';
    for (auto x : bs) cout << x + 1 << ' ';
    cout << '\n';
}