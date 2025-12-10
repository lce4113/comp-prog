// CSES Advanced Techniques: Meet in the MIddle

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, sm;
    cin >> n >> sm;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    unordered_map<int, int> sm1;
    int n1 = n / 2, n2 = n - n / 2;
    sm1.reserve(1 << n1);
    for (int i = 0; i < (1 << n1); i++) {
        int c = 0;
        for (int j = 0; j < n1; j++) {
            if ((i & (1 << j)) == 0) continue;
            c += a[j];
        }
        sm1[c]++;
    }

    int ans = 0;
    for (int i = 0; i < (1 << n2); i++) {
        int c = 0;
        for (int j = 0; j < n2; j++) {
            if ((i & (1 << j)) == 0) continue;
            c += a[n1 + j];
        }
        ans += sm1[sm - c];
    }

    cout << ans << '\n';
}