// Codeforces Round 1046: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

// const int N = 100;
const int N = 25000;
const int MW = 1e5;

int q(vector<int> &ws) {
    if (ws.empty()) return 0;
    cout << "? " << ws.size();
    for (auto w : ws) cout << ' ' << w;
    cout << endl;
    int n;
    cin >> n;
    return n;
}

void res(int W) { cout << "! " << W << endl; }

int check(vector<int> &ws, int W) {
    int c = 0, l = 1;
    for (auto w : ws) {
        if (c + w > W) {
            c = w, l++;
        } else {
            c += w;
        }
    }
    return l;
}

pair<int, int> bin(vector<int> &ws, int l) {
    pair<int, int> res;
    int L = 0, R = MW + 1;
    while (R - L > 1) {
        int m = (L + R) / 2;
        if (check(ws, m) < l) {
            R = m;
        } else {
            L = m;
        }
    }
    res.s = L;
    L = 0, R = MW + 1;
    bool ok = 0;
    while (R - L > 1) {
        int m = (L + R) / 2;
        int c = check(ws, m);
        if (c == l) ok = 1;
        if (c <= l) {
            R = m;
        } else {
            L = m;
        }
    }
    if (!ok) return {-1, -1};
    res.f = R;
    return res;
}

void solve() {
    // vector<int> ws1(N / 8, 1);
    // for (int i = 0; i < N / 8; i++) {
    //     for (int c = 1; c <= 100 && i < N / 8; c++, i++) {
    //         ws1[i] = c;
    //     }
    // }
    int M = 6000;
    int B = 136;
    vector<int> ws1(M, B);
    int l = q(ws1);
    if (l == 0) {
        vector<int> ws2(N - M, 1);
        int l2 = q(ws2);
        auto [lo, hi] = bin(ws2, l2);
        res(lo);
        return;
    }
    auto [lo, hi] = bin(ws1, l);
    if (lo == hi) {
        res(lo);
        return;
    }
    lo++;
    vector<int> ws2;
    for (int i = lo + 1; i <= hi; i++) {
        ws2.push_back(lo);
        ws2.push_back(i - lo);
    }
    int l2 = q(ws2);
    if (l2 == 0) {
        res(lo - 1);
        return;
    }
    int lines = l2 - (hi - lo);
    res(hi - lines);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // int M = N * 0.9;
    // int B = 1;

    // for (int M = 1e3; M <= 1e5 / 4; M += 1e3) {
    //     cout << "M = " << M << '\n';
    //     for (int B = 50; (B * B + M) <= 1e5 / 4; B++) {
    //         vector<int> ws(M, B);
    //         // for (auto x : ws) cout << x << ' ';
    //         // cout << '\n';
    //         int mx = -1;
    //         for (int i = 1; i <= 1e2; i++) {
    //             auto x = bin(ws, i);
    //             mx = max(mx, x.s - x.f);
    //         }
    //         // if (M % 5 == 0 && B % 5 == 0)
    //         //     cout << "max diff: " << M << ' ' << B << ' ' << mx <<
    //         '\n'; if (M + 2 * mx <= 1e5 / 4) {
    //             cout << M << ' ' << B << ' ' << mx << '\n';
    //             return 0;
    //         }
    //         // max diff = mx
    //         // B^2 + B <= 1e5/4
    //         // B + 2*mx <= 1e5/4
    //     }
    // }

    // cout << check(ws, 100) << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}