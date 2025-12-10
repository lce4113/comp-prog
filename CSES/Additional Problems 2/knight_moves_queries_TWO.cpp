// CSES Additional Problems II: Knight Moves Queries

#include <bits/stdc++.h>
using namespace std;

int dist(int x, int y) {
    x = abs(x), y = abs(y);
    if (x < y) swap(x, y);
    if (x == 1 && y == 0) return 3;
    if (x == 2 && y == 2) return 4;
    return max((x + 1) / 2, (x + y + 2) / 3);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << dist(x - 1, y - 1) << '\n';
    }
}
