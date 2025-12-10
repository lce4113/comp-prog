// Codeforces Round #967: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

struct Seg {
    using F = int (*)(int, int);
    F comb = [](int a, int b) { return a + b; };
    int n, N;
    int ID = 0;
    vector<int> seg;

    Seg(vector<int> a) { init(a); }
    Seg(vector<int> a, int _ID) : ID(_ID) { init(a); }
    Seg(vector<int> a, F _comb) : comb(_comb) { init(a); }
    Seg(vector<int> a, F _comb, int _ID) : comb(_comb), ID(_ID) { init(a); }

    void init(vector<int> a) {
        N = a.size();
        n = binexp(2, ceil(log2(N)));
        seg.assign(n, 0);
        for (auto x : a) seg.push_back(x);
        for (int i = 0; i < n - N; i++) seg.push_back(0);
        for (int i = n - 1; i >= 0; i--) calc(i);
    }

    int binexp(int a, int b) {
        int ans = 1;
        for (; b; a *= a) {
            if (b % 2) ans *= a;
            b /= 2;
        }
        return ans;
    }

    void calc(int i) { seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }

    int get(int i) {
        assert(i >= 0), assert(i < N);
        return seg[i + n];
    }

    void u(int i, int val) {
        assert(i >= 0), assert(i < N);
        i = i + n, seg[i] = val;
        for (i /= 2; i; i /= 2) calc(i);
    }

    int q(int L) { return q(L, L + 1); }
    int q(int L, int R) { return q(L, R, 0, n, 1); }
    int q(int L, int R, int l, int r, int i) {
        assert(L >= 0), assert(L <= N);
        assert(R >= 0), assert(R <= N);
        if (l >= R || r <= L) return ID;
        if (l >= L && r <= R) return seg[i];
        int ans = ID, m = (l + r) / 2;
        ans = comb(ans, q(L, R, l, m, 2 * i));
        ans = comb(ans, q(L, R, m, r, 2 * i + 1));
        return ans;
    }
};

vector<int> check(int n, vector<int> a) {
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int &x : a) {
    // cin >> x;
    // x--;
    // }

    vector l(n + 1, INT_MAX);
    for (int i = 0; i < n; i++) l[a[i]] = i;

    priority_queue<int, vector<int>, greater<int>> ls(l.begin(), l.end());
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
        mx_cand, mn_cand;
    vector<bool> used(n, false);

    for (int i = 0; i <= ls.top(); i++) {
        mx_cand.push({-a[i], i});
        mn_cand.push({a[i], i});
    }

    vector<int> b;
    int i = 0;
    while (!mn_cand.empty()) {
        auto [x, pos] = (b.size() % 2 == 0 ? mx_cand.top() : mn_cand.top());
        if (b.size() % 2 == 0) {
            mx_cand.pop();
            x *= -1;
        } else {
            mn_cand.pop();
        }
        b.emplace_back(x);
        i = pos + 1, used[x] = true;
        while (ls.top() != INT_MAX and used[a[ls.top()]]) {
            int j = ls.top();
            ls.pop();
            for (int k = j + 1; k <= min(ls.top(), n - 1); k++) {
                mx_cand.push({-a[k], k});
                mn_cand.push({a[k], k});
            }
        }
        while (!mx_cand.empty() and
               (used[-mx_cand.top()[0]] or mx_cand.top()[1] < i))
            mx_cand.pop();
        while (!mn_cand.empty() and
               (used[mn_cand.top()[0]] or mn_cand.top()[1] < i))
            mn_cand.pop();
    }

    return b;
}

void solve() {
    // vector<int> solve(int n, vector<int> a) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int, vector<int>> mp;
    vector<int> last(n + 1, -1);
    for (int i = 0; i < n; i++) {
        last[a[i]] = i;
        mp[a[i]].push_back(i);
    }
    set<int> ls;
    for (auto x : last) {
        if (x != -1) ls.insert(x);
    }

    // cout << "last: ";
    // for (auto x : last) cout << x << ' ';
    // cout << '\n';
    // cout << "ls: ";
    // for (auto x : ls) cout << x << ' ';
    // cout << '\n';

    Seg mx = Seg(a, [](int a, int b) { return max(a, b); });
    Seg mn = Seg(a, [](int a, int b) { return min(a, b); }, 1e9);
    // cout << mx.q(1, 3) << '\n';
    // cout << mn.q(1, 3) << '\n';

    set<int> c;
    bool big = true;
    vector<int> ans;
    int l = 0;
    for (int i = 0; i < n; i++) {
        while (ls.size() && i == *ls.begin()) {
            int nxt = big ? mx.q(l, *ls.begin() + 1) : mn.q(l, *ls.begin() + 1);
            l = *lower_bound(mp[nxt].begin(), mp[nxt].end(), l) + 1;
            for (auto x : mp[nxt]) mn.u(x, 1e9), mx.u(x, 0);
            ans.push_back(nxt);
            ls.erase(last[nxt]);
            big = !big;
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    // return ans;
}

int32_t main() {
    // for (int i1 = 1; i1 <= 5; i1++) {
    //     for (int i2 = 1; i2 <= 5; i2++) {
    //         for (int i3 = 1; i3 <= 5; i3++) {
    //             for (int i4 = 1; i4 <= 5; i4++) {
    //                 for (int i5 = 1; i5 <= 5; i5++) {
    //                     for (int i6 = 1; i6 <= 5; i6++) {
    //                         vector<int> a = {i1, i2, i3, i4, i5, i6};
    //                         cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4
    //                              << ' ' << i5 << ' ' << i6 << '\n';
    //                         int n = 6;
    //                         vector<int> ans1 = solve(n, a);
    //                         vector<int> ans2 = check(n, a);
    //                         for (auto x : ans1) cout << x << ' ';
    //                         cout << '\n';
    //                         for (auto x : ans2) cout << x << ' ';
    //                         cout << '\n';
    //                         bool same = true;
    //                         for (int i = 0; i < ans1.size(); i++) {
    //                             if (ans1[i] != ans2[i]) same = false;
    //                         }
    //                         if (!same) {
    //                             cout << "ohno\n";
    //                             return 0;
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