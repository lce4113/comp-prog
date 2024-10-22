#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mni = 0, mxi = 0;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        int mna = abs(a[i] - a[mni]) - (i - mni) * c;
        ans = max(ans, mna);
        int mxa = abs(a[i] - a[mxi]) - (i - mxi) * c;
        ans = max(ans, mxa);
        if (a[i] > a[mxi] - c * (i - mxi)) mxi = i;
        if (a[i] < a[mni] + c * (i - mni)) mni = i;
        cout << ans << ' ';
    }
    cout << '\n';
}