// BAPC 2023: Problem H

#include <bits/stdc++.h>
using namespace std;

map<pair<char, char>, int> conv = {
    {{'r', 'g'}, 0}, {{'r', 'w'}, 1}, {{'r', 'b'}, 2},
    {{'g', 'w'}, 3}, {{'g', 'b'}, 4}, {{'w', 'b'}, 5},

    {{'g', 'r'}, 0}, {{'w', 'r'}, 1}, {{'b', 'r'}, 2},
    {{'w', 'g'}, 3}, {{'b', 'g'}, 4}, {{'b', 'w'}, 5},
};

map<int, int> opp = {{0, 5}, {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0}};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (auto &x : a) cin >> x;
    int g = gcd(w, h);
    int vec[g][6][w][w];
    memset(vec, 0, sizeof(vec));
    for (int y = 0; y < h; y++) {
        for (int l = 0; l < w; l++) {
            for (int r = l + 1; r < w; r++) {
                if (a[y][l] == a[y][r]) continue;
                vec[y % g][conv[{a[y][l], a[y][r]}]][l][r] = 1;
            }
        }
    }
    for (int y = 0; y < h; y++) {
        for (int l = 0; l < w; l++) {
            for (int r = l + 1; r < w; r++) {
                if (a[y][l] == a[y][r]) continue;
                vector<int> mods = {
                    ((r - l + y) % g + g) % g,
                    ((l - r + y) % g + g) % g,
                };
                for (auto mod : mods) {
                    if (vec[mod][opp[conv[{a[y][l], a[y][r]}]]][l][r]) {
                        cout << "possible\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "impossible\n";
}