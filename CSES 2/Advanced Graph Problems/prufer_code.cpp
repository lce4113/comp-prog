// CSES Advanced Graph Problems: Prüfer Code

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n - 2), lst(n, -1);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    for (int i = 0; i < n - 2; i++) lst[a[i]] = i;
    set<int> cur;
    for (int i = 0; i < n; i++) {
        if (lst[i] == -1) cur.insert(i);
    }
    for (int i = 0; i < n - 2; i++) {
        int v = *cur.begin();
        cur.erase(v);
        cout << v + 1 << ' ' << a[i] + 1 << '\n';
        if (lst[a[i]] == i) cur.insert(a[i]);
    }
    cout << *cur.begin() + 1 << ' ' << *(++cur.begin()) + 1 << '\n';
}