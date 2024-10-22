#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 9;
const int P = 998244353;

const int MAXN = 2e5;
vector<int> hpfs(MAXN + 1, 1), hipfs(MAXN + 1, 1);
vector<int> hpfs2(MAXN + 1, 1), hipfs2(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b > 0; a = (a * a) % MOD) {
        if (b % 2) ans = (ans * a) % MOD;
        b /= 2;
    }
    return ans;
}

int H(int h, int x) {
    int ans = h;
    ans = (ans * (P - (x % MOD))) % MOD;
    return ans;
}

int H_inv(int h, int x) {
    int ans = h;
    ans = (ans * binexp(P - (x % MOD))) % MOD;
    return ans;
}

bool neq(int a, int b) {
    return (hpfs[b] * hipfs[a]) % MOD != (hpfs2[b] * hipfs2[a]) % MOD;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    string dir;
    cin >> dir;

    set<int> lr;
    lr.insert(0), lr.insert(n);
    for (int i = 1; i < n; i++) {
        if (dir[i - 1] == 'L' && dir[i] == 'R') lr.insert(i);
    }
    // for (auto x : lr) cout << x << ' ';
    // cout << '\n';

    vector<int> sa;
    for (int i = 1; i <= n; i++) sa.push_back(i);

    for (int i = 0; i < n; i++) hpfs[i + 1] = H(hpfs[i], a[i]);
    for (int i = 0; i < n; i++) hipfs[i + 1] = H_inv(hipfs[i], a[i]);
    for (int i = 0; i < n; i++) hpfs2[i + 1] = H(hpfs2[i], sa[i]);
    for (int i = 0; i < n; i++) hipfs2[i + 1] = H_inv(hipfs2[i], sa[i]);

    // for (int i = 0; i < n; i++) cout << hpfs[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << hpfs2[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << hipfs[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << hipfs2[i] << ' ';
    // cout << '\n';
    // cout << (hpfs2[1] * hipfs2[1]) % MOD << ' ' << (hpfs[4] * hipfs[3]) % MOD
    //      << '\n';

    int num_neq = 0;
    for (auto curr = lr.begin();; curr++) {
        auto next = curr;
        next++;
        if (next == lr.end()) break;
        if (neq(*curr, *next)) num_neq++;
    }
    // cout << num_neq << '\n';

    while (q--) {
        int ind;
        cin >> ind;
        ind--;
        dir[ind] = (dir[ind] == 'L' ? 'R' : 'L');
        // cout << dir[ind] << '\n';
        if ((dir[ind] == 'R' && dir[ind + 1] == 'R') ||
            (dir[ind - 1] == 'L' && dir[ind] == 'L')) {
            auto m = (dir[ind] == 'R' ? lr.lower_bound(ind + 1)
                                      : lr.lower_bound(ind));
            auto r = m;
            r++;
            auto l = m;
            l--;
            // cout << *l << ' ' << *m << ' ' << *r << '\n';
            if (neq(*l, *m)) num_neq--;
            if (neq(*m, *r)) num_neq--;
            if (neq(*l, *r)) num_neq++;
            lr.erase(m);
        }
        if ((dir[ind] == 'L' && dir[ind + 1] == 'R') ||
            (dir[ind - 1] == 'L' && dir[ind] == 'R')) {
            auto m = (dir[ind] == 'L' ? ind + 1 : ind);
            auto r = lr.lower_bound(ind + 1);
            auto l = r;
            l--;
            if (neq(*l, *r)) num_neq--;
            if (neq(*l, m)) num_neq++;
            if (neq(m, *r)) num_neq++;
            lr.insert(m);
        }
        // cout << num_neq << '\n';
        if (num_neq == 0) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}