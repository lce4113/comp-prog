// CSES Geometry: Line Segments Trace I

#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<pair<int, int>> L;
#define f first
#define s second

int n, m;

double inter(int i, int j) {
    int si = (L[i].s - L[i].f) / m;
    int sj = (L[j].s - L[j].f) / m;
    if (si == sj) return -1;
    return (double)(L[j].f - L[i].f) / (si - sj);
}

int eval(int i, int x) {
    int slope = (L[i].s - L[i].f) / m;
    return slope * x + L[i].f;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    L.assign(n, {0, 0});
    for (auto &p : L) cin >> p.f >> p.s;
    sort(L.rbegin(), L.rend());
    deque<int> Q;
    Q.push_back(0);
    for (int i = 1; i < n; i++) {
        double i1 = inter(Q.back(), i);
        if (i1 < 0 || i1 > m) continue;
        while (Q.size() >= 2 &&
               inter(Q.back(), Q[Q.size() - 2]) >= inter(Q.back(), i))
            Q.pop_back();
        Q.push_back(i);
    }
    for (int x = 0; x <= m; x++) {
        while (Q.size() >= 2 && x > inter(Q[0], Q[1])) Q.pop_front();
        cout << eval(Q.front(), x) << ' ';
    }
    cout << '\n';
}