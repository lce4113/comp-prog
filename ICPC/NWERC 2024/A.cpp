// NWERC 2024: Problem A

#include <bits/stdc++.h>
using namespace std;

string last(string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (isupper(s[i])) return s.substr(i, n - i);
    }
    return "";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    string _;
    getline(cin, _);
    vector<pair<string, string>> a(n);
    for (auto &x : a) {
        getline(cin, x.second);
        x.first = last(x.second);
        // cout << "asdf: " << x.first << '\n';
    }
    sort(a.begin(), a.end());
    for (auto x : a) {
        cout << x.second << '\n';
    }
}