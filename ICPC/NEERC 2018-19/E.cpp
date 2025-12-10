#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<string> path = {
        "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "b8", "b7", "b6",
        "b5", "b4", "b3", "b2", "b1", "c1", "c2", "c3", "c4", "c5", "c6",
        "c7", "c8", "d8", "d7", "d6", "d5", "d4", "d3", "d2", "d1", "e1",
        "e2", "e3", "e4", "e5", "e6", "e7", "e8", "f8", "f7", "f6", "f5",
        "f4", "f3", "f2", "f1", "g1", "g2", "g3", "g4", "g5", "g6", "g8",
        "g7", "h7", "h6", "h5", "h4", "h3", "h2", "h1", "h8"};
    vector<string> rem = {"a2", "a3", "a4", "a5", "a6", "a7", "b2", "b3",
                          "b4", "b5", "b6", "b7", "c2", "c3", "c4", "c5",
                          "c6", "c7", "d2", "d3", "d4", "d5", "d6", "d7"};

    int n;
    cin >> n;
    n++;
    if (n < 49) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                int c = i % 2 ? 6 - j : j;
                char C = 'a' + i;
                cout << C << c + 1 << ' ';
                if (7 * i + j + 1 == n - 2) {
                    cout << "h" << c + 1 << ' ';
                    cout << "h8\n";
                    return 0;
                }
            }
        }
    } else {
        set<string> crem;
        for (int i = 0; i < 64 - n; i++) {
            crem.insert(rem[i]);
        }
        for (auto c : path) {
            if (crem.count(c)) continue;
            cout << c << ' ';
        }
        cout << '\n';
    }
}