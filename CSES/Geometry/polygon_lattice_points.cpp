// CSES Geometry: Polygon Lattice Points

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using P = pair<int, int>;

int cross(P a, P b) { return a.x * b.y - a.y * b.x; }

int boundary(P v) { return gcd(v.y, v.x) + 1; }
int boundary(P a, P b) { return boundary({b.x - a.x, b.y - a.y}); }
int boundary(vector<P> &A) {
    int n = A.size();
    int ans = boundary(A.back(), A[0]) - 1;
    for (int i = 0; i < n - 1; i++) {
        ans += boundary(A[i], A[i + 1]) - 1;
    }
    return ans;
}

int area(vector<P> &A) {
    int n = A.size();
    int ans = cross(A.back(), A[0]);
    for (int i = 0; i < n - 1; i++) ans += cross(A[i], A[i + 1]);
    return abs(ans) / 2;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<P> A(n);
    for (auto &c : A) cin >> c.x >> c.y;

    int Ar = area(A);
    int B = boundary(A);
    int I = Ar + 1 - B / 2;
    // cout << Ar << '\n';
    cout << I << ' ' << B << '\n';
}