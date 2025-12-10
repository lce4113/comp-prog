// CSES Intro Problems: Mex Grid Construction

#include <bits/stdc++.h>
using namespace std;

#define int long long

int mex(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] != i) return i;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> nums;
            for (int x = 0; x < i; x++) nums.push_back(a[x][j]);
            for (int y = 0; y < j; y++) nums.push_back(a[i][y]);
            a[i][j] = mex(nums);
        }
    }

    for (auto x : a) {
        for (auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
