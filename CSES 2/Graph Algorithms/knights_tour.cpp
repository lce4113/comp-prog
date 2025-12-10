// CSES Graph Algorithms: Knights Tour

#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<vector<int>> board(N, vector<int>(N, 0));

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int curr = 0;

int num_adj(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (board[x][y]) continue;
        ans++;
    }
    return ans;
}

void rec(int x, int y) {
    board[x][y] = ++curr;
    if (curr == N * N) {
        for (auto row : board) {
            for (auto cell : row) cout << cell << ' ';
            cout << '\n';
        }
        exit(0);
    }

    vector<pair<int, pair<int, int>>> adj;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (board[nx][ny]) continue;
        adj.push_back({num_adj(nx, ny), {nx, ny}});
    }
    sort(adj.begin(), adj.end());
    for (auto [_, p] : adj) {
        auto [nx, ny] = p;
        rec(nx, ny);
    }

    board[x][y] = 0, curr--;
}

int main() {
    int x, y;
    cin >> y >> x;
    x--, y--;
    rec(x, y);
}
