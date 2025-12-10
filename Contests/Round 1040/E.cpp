// Codeforces Round 1040: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n;
vector<int> bask;
vector<int> bps;
vector<int> tris;
int pl = 1, pr = 2;
int base = 0;
string ans;

void getq() {
    int tot = 0;
    int len = 0;
    vector<int> cs;
    for (int i = 1; len + i * 2 + 1 <= 1000 && tris.size() + 1 <= n; i++) {
        int l = i / 2, r = i - l - 1;
        int tri = i * (i + 1) / 2 - l * (l + 1) / 2 - r * (r + 1) / 2;
        if (tri <= tot) continue;
        base += l * (l + 1) / 2 + r * (r + 1) / 2;
        tris.push_back(tri);
        len += i * 2 + 1;
        tot += tri;

        for (int j = 0; j < l; j++) {
            bask.push_back(pl);
            bask.push_back(pr);
        }
        bps.push_back(bask.size());
        for (int j = 0; j < r + 1; j++) {
            bask.push_back(pl);
            bask.push_back(pr);
        }
        bask.push_back(pr);
    }
}

int q(vector<int> ask) {
    int k = ask.size();
    cout << "? " << k << ' ';
    for (auto x : ask) cout << x << ' ';
    cout << endl;
    int num;
    cin >> num;
    return num;
}

void qsol(vector<int> ps) {
    vector<int> cbask = bask;
    for (int i = 0; i < ps.size(); i++) {
        cbask[bps[i]] = ps[i];
    }
    int num = q(cbask) - base;
    for (int i = tris.size() - 1; i >= 0; i--) {
        if (num >= tris[i]) {
            num -= tris[i];
            ans[ps[i] - 1] = '(';
        }
    }
}

void res(string ask) { cout << "! " << ask << endl; }

vector<int> rng(int l, int r, int pre = -1) {
    vector<int> res;
    if (pre != -1) res.push_back(pre);
    for (int i = l; i <= r; i++) res.push_back(i);
    return res;
}

void setlr() {
    int l = 2, r = n;
    while (r - l > 0) {
        int m = (l + r) / 2;
        vector<int> c = rng(l, m, 1);
        c.push_back(1);
        if (q(c)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (q({l, 1}) == 1) {
        pl = l, pr = 1;
    } else {
        pl = 1, pr = l;
    }
}

void solve() {
    cin >> n;

    bask.clear();
    bps.clear();
    tris.clear();
    base = 0;
    ans.assign(n, ')');
    setlr();
    getq();

    // for (auto x : bask) cout << x << ' ';
    // cout << '\n';
    // for (auto x : bps) cout << x << ' ';
    // cout << '\n';
    // for (auto x : tris) cout << x << ' ';
    // cout << '\n';

    for (int i = 1; i + bps.size() - 1 <= n; i += bps.size()) {
        qsol(rng(i, i + bps.size() - 1));
    }
    qsol(rng(n - bps.size() + 1, n));
    res(ans);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}