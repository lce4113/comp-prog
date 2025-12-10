#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<char> valid(1 << n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                valid[(1 << i) | (1 << j) | (1 << k)] = ((a[i] ^ a[j] ^ a[k]) == 0);
            }
        }
    }

    int ans = n;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (!valid[mask]) {
            ans = min(ans, n - __builtin_popcount(mask));
        } else {
            for (int i = 0; i < n; ++i) {
                valid[mask | (1 << i)] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
