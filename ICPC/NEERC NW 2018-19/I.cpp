// NEERC NW 2018-19: Problem I

#include <bits/stdc++.h>
using namespace std;

vector<int> q(vector<int> &ask) {
    cout << "? ";
    cout << ask.size() << ' ';
    for (auto x : ask) cout << x << ' ';
    cout << endl;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    return a;
}

signed main() {
    // cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    if (n == 1) {
        vector<int> ask = {1};
        vector<vector<int>> ans;
        ans.push_back(q(ask));
        cout << "! ";
        for (auto v : ans) {
            cout << v.size() << ' ';
            for (auto x : v) cout << x << ' ';
        }
        cout << endl;
        return 0;
    }
    vector<vector<int>> ans;
    vector<int> ask;
    for (int i = 1; i < n / 2; i++) {
        ask.push_back(i);
        ask.push_back(i);
    }
    ask.push_back(n / 2);
    vector<int> d = q(ask);
    // cout << "RESED\n";
    int m = d.size();
    for (int i = 0; i < m;) {
        vector<int> c;
        while (i < m && count(c.begin(), c.end(), d[i]) == 0)
            c.push_back(d[i]), i++;
        ans.push_back(c);
        i += c.size();
    }
    // cout << "ANS1\n";
    ask.clear();
    for (int i = n / 2 + 1; i < n; i++) {
        ask.push_back(i);
        ask.push_back(i);
    }
    ask.push_back(n);
    d = q(ask);
    m = d.size();
    for (int i = 0; i < m;) {
        vector<int> c;
        while (i < m && count(c.begin(), c.end(), d[i]) == 0)
            c.push_back(d[i]), i++;
        ans.push_back(c);
        i += c.size();
    }
    cout << "! ";
    for (auto v : ans) {
        cout << v.size() << ' ';
        for (auto x : v) cout << x << ' ';
    }
    cout << endl;
}