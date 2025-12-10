// 2023-2024 ICPC East North America Regional Contest (ECNA 2023)
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long double
#define f first
#define s second

int ok = 1;

bool between(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
    return (x.f <= y.f && y.f <= z.f && x.s <= y.s && y.s <= z.s);
}

pair<int, int> inter(pair<int, int> a1, pair<int, int> a2, pair<int, int> b1,
                     pair<int, int> b2) {
    if (a1.f == a2.f && b1.f == b2.f) {
        ok = 0;
        return {0, 0};
    }
    if (b1.f == b2.f) swap(a1, b1), swap(a2, b2);
    int m2 = (b1.s - b2.s) / (b1.f - b2.f);
    if (a1.f == a2.f) return {a1.f, (a1.f - b1.f) * m2 + b1.s};
    int m1 = (a1.s - a2.s) / (a1.f - a2.f);
    if (m1 == m2) {
        ok = 0;
        return {0, 0};
    }
    // (x-a1.f)*m1 + a1.s = (x-b1.f)*m2 + b1.s
    // x*m1-a1.f*m1 = x*m2-b1.f*m2 + b1.s-a1.s
    // x = (a1.f*m1-b1.f*m2 + b1.s-a1.s)/(m1-m2)
    x = (a1.f * m1 - b1.f * m2 + b1.s - a1.s) / (m1 - m2);
    return {x, (x - b1.f) * m2 + b1.s};
}

int rect(int L, int R, int B, int T) {
    return (floor(R) - ceil(L) + 1) * (floor(T) - ceil(B) + 1);
}

int lc(int x, int y) {}

int rt(vector<pair<int, int>> vs) {
    if () rect();
}

int count(vector<pair<int, int>> vs) {
    int L = 1e18, R = -1e18, B = 1e18, T = -1e18;
    for (auto x : vs) {
        L = min(L, x.f), R = max(R, x.f), B = min(B, x.s), T = max(T, x.s);
    }
    int tot = rect(L, R, B, T);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f >> x.s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto x = inter(a[i], a[(i + 1) % n], a[(i + 3) % n], a[(i + 2) % n]);
        if (!ok || between(x, a[i], a[(i + 1) % n])) {
            cout << "infinitely many\n";
            return;
        }
        ans += count({x, a[(i + 1) % n], a[(i + 2) % n]});
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}