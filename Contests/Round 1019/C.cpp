// Codeforces Round 1019: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;
vector<int> a;

bool Lc() {
    int ML = 0, MR = 0, md = -1e9, mL, mR, ml;
    for (int i = 1; i < n; i++) {
        ML += a[i] <= k;
        MR += a[i] > k;
    }
    md = ML - MR, mL = ML, mR = MR, ml = 1;
    int l = 1, r = n - 2;
    while (l < n - 2) {
        ML -= a[l] <= k;
        MR -= a[l] > k;
        l++;
        // cout << md << ' ' << ML << ' ' << MR << '\n';
        if (ML - MR > md) md = ML - MR, mL = ML, mR = MR, ml = l;
    }
    ML = mL, MR = mR, l = ml;
    // cout << ML << ' ' << MR << ' ' << l << '\n';

    int L = a[n - 1] <= k, R = a[n - 1] > k;
    ML -= a[n - 1] <= k, MR -= a[n - 1] > k;
    while (r > l && (R > L || MR > ML || L == 0)) {
        R += (a[r] > k);
        L += (a[r] <= k);
        MR -= (a[r] > k);
        ML -= (a[r] <= k);
        r--;
    }
    if (L < R) return false;
    if (ML < MR) return false;
    return true;
}

bool LR() {
    int l = 1, r = n - 2;
    int L = a[0] <= k, R = a[0] > k;
    while (l < n - 2 && (R > L || L == 0)) {
        R += (a[l] > k);
        L += (a[l] <= k);
        l++;
    }
    // cout << l << '\n';
    if (L < R) return false;
    L = a[n - 1] <= k, R = a[n - 1] > k;
    while (r > l && (R > L || L == 0)) {
        // cout << L << ' ' << R << ' ' << r << '\n';
        R += (a[r] > k);
        L += (a[r] <= k);
        r--;
    }
    if (L < R) return false;
    return true;
}

void solve() {
    cin >> n >> k;
    a.clear();
    a.assign(n, 0);
    for (auto &x : a) cin >> x;

    if (LR()) {
        cout << "YES\n";
        return;
    }
    if (Lc()) {
        cout << "YES\n";
        return;
    }
    reverse(a.begin(), a.end());
    if (Lc()) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
