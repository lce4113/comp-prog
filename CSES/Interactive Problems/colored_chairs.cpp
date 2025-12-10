// CSES Interactive Problems: Colored Chairs

#include <bits/stdc++.h>
using namespace std;

#define Q(n, V)                \
    cout << "? " << n << endl; \
    char R;                    \
    cin >> R;                  \
    V = R == 'R';

int main() {
    int n, m, c, l = 1, r, A;
    cin >> n;
    Q(1, A);
    for (r = n + 1; r - l > 1;) {
        m = (l + r) / 2;
        Q(m, c);
        if ((m % 2 == l % 2) ^ (c == A)) {
            r = m;
        } else {
            l = m, A = c;
        }
    }
    cout << "! " << l << endl;
}