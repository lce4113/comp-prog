#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t dfs_matching(vector<vector<int32_t>>& graph, vector<int32_t>& btoa) {
    vector<bool> vis;
    auto find = [&](auto self, int v) -> bool {
        if (btoa[v] == -1) {
            return true;
        }
        vis[v] = true;
        int u = btoa[v];
        for (int w : graph[u]) {
            if (!vis[w] && self(self, w)) {
                btoa[w] = u;
                return true;
            }
        }

        return false;
    };

    for (int32_t i = 0; i < graph.size(); ++i) {
        vis.assign(btoa.size(), false);
        for (int32_t j : graph[i]) {
            if (find(find, j)) {
                btoa[j] = i;
                break;
            }
        }
    }

    return btoa.size() - count(btoa.begin(), btoa.end(), -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t n, k;
    cin >> n >> k;
    vector<int32_t> a(1 << n);
    for (auto& x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end(), greater<int32_t>());

    int32_t ans = 0;
    while (a.size() > 1) {
        int32_t h = a.size() / 2;

        vector<vector<int32_t>> graph(h);
        for (int32_t i = 0; i < h; ++i) {
            for (int32_t j = h; j < a.size(); ++j) {
                assert(a[i] > a[j]);
                if (a[i] <= a[j] + k) {
                    graph[i].push_back(j - h);
                } else {
                    break;
                }
            }
        }

        vector<int32_t> btoa(h, -1);
        ans += dfs_matching(graph, btoa);

        a.resize(h);
    }

    cout << ans << '\n';

    return 0;
}
