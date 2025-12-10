// CSES Additional Problems I: Swap Game

#include <bits/stdc++.h>
using namespace std;

#define int long long

int to_int(vector<int> &a) {
    int res = 0;
    for (auto x : a) res *= 10, res += x;
    return res;
}

vector<int> from_int(int n) {
    vector<int> res(9);
    for (int i = 8; i >= 0; i--, n /= 10) res[i] = n % 10;
    return res;
}

vector<vector<int>> adj(vector<int> a) {
    vector<vector<int>> res;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            swap(a[x * 3 + y], a[(x + 1) * 3 + y]);
            res.push_back(a);
            swap(a[x * 3 + y], a[(x + 1) * 3 + y]);
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 2; y++) {
            swap(a[x * 3 + y], a[x * 3 + y + 1]);
            res.push_back(a);
            swap(a[x * 3 + y], a[x * 3 + y + 1]);
        }
    }
    return res;
}

int32_t main() {
    vector<int> a(9);
    for (auto &x : a) cin >> x;
    if (to_int(a) == 123456789) {
        cout << "0\n";
        return 0;
    }
    unordered_set<int> vis({to_int(a)});
    queue<pair<int, int>> Q;
    Q.push({to_int(a), 0});
    while (Q.size()) {
        auto [v, d] = Q.front();
        Q.pop();
        for (auto to : adj(from_int(v))) {
            auto toi = to_int(to);
            if (toi == 123456789) {
                cout << d + 1 << '\n';
                return 0;
            }
            if (vis.count(toi)) continue;
            Q.push({toi, d + 1});
            vis.insert(toi);
        }
    }
}