// Codeforces Educational Round 173: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int l, r, G;

pair<int, int> check() {
    // cin >> l >> r >> G;
    int ml = -1, mr = -1;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            if (gcd(i, j) == G && (j - i > mr - ml || ml == -1)) ml = i, mr = j;
        }
    }
    return {ml, mr};
}

// void solve() {
pair<int, int> solve() {
    // cin >> l >> r >> G;
    int gl = ceil((long double)l / G);
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
    int al = (glm == -1 ? -1 : glm * G), ar = (grm == -1 ? -1 : grm * G);
    // cout << al << ' ' << ar << '\n';
    return {al, ar};
}

int32_t main() {
    for (int i1 = 1; i1 <= 100; i1++) {
        for (int i2 = i1; i2 <= 500; i2++) {
            for (int i3 = 1; i3 <= 20; i3++) {
                l = i1, r = i2, G = i3;
                cout << l << ' ' << r << ' ' << G << '\n';
                auto a1 = solve();
                auto a2 = check();
                cout << a1.f << ' ' << a1.s << '\n';
                cout << a2.f << ' ' << a2.s << '\n';
                if (a1 != a2) {
                    cout << "ohno\n";
                    return 0;
                }
            }
        }
    }
    // int t = 1;
    // cin >> t;
    // while (t--) check();
}