// Codeforces Educational Round 173: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int l, r, G;
    cin >> l >> r >> G;
    // int gl = ceil((long double)l / G);
    int gl = (l + G - 1) / G;
    int gr = r / G;
    int glc = gl, grc = gr;
    int glm = -1, grm = -1;
    // cout << glc << ' ' << grc << '\n';
    while (glc <= grc) {
        // cout << glc << ' ' << grc << '\n';
        while (grc >= glc && gcd(glc, grc) != 1) grc--;
        if (grc < glc) break;
        // cout << "c: " << glc << ' ' << grc << '\n';
        if (glm == -1 || grc - glc > grm - glm) glm = glc, grm = grc;
        // cout << "m: " << glm << ' ' << grm << '\n';
        if (grc == gr) break;
        grc = gr;
        glc++;
    }
    // cout << glm << ' ' << grm << '\n';
    cout << (glm == -1 ? -1 : glm * G) << ' ' << (grm == -1 ? -1 : grm * G)
         << '\n';
    // cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}