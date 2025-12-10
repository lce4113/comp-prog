#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            b.push_back(i);
        }
    }
    b.push_back(n);
    int ans = 0;
    vector<vector<int>> d(m + 1, vector<int>(m + 1));
    for (auto x : b) cout << x << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++) {
        vector<int> st1, st2;
        for (int j = b[i] + 1; j < b[i + 1]; j++) {
            if (a[j] > 0)
                st1.push_back(a[j]);
            else
                st2.push_back(abs(a[j]));
        }
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());
        cout << i << '\n';
        for (int j = 0; j <= i + 1; j++) {
            int ans1 = upper_bound(st1.begin(), st1.end(), j) - st1.begin();
            int ans2 =
                upper_bound(st2.begin(), st2.end(), i + 1 - j) - st2.begin();
            if (j != 0)
                d[i + 1][j] =
                    max(d[i][j] + ans1 + ans2, d[i][j - 1] + ans2 + ans1);
            else
                d[i + 1][j] = d[i][j] + ans1 + ans2;
            ans = max(ans, d[i + 1][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}