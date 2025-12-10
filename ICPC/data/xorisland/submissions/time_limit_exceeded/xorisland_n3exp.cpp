#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    int ans = n;
    for (int mask = (1 << n) - 1; mask >= 0; --mask) {
        bool seen_triple = false;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = i + 1; j < n; ++j) {
                if ((mask & (1 << j)) == 0) continue;
                for (int k = j + 1; k < n; ++k) {
                    if ((mask & (1 << k)) == 0) continue;

                    seen_triple |= (a[i] ^ a[j] ^ a[k]) == 0;
                }
            }
        }

        if (!seen_triple) {
            ans = min(ans, n - __builtin_popcount(mask));
        }
    }

    cout << ans << '\n';

    return 0;
}
