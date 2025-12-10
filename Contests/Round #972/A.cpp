#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string vowels = "aeiou";
    vector<int> v(5, 0);
    for (int i = 0; i < n; i++) {
        v[i % 5]++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < v[i]; j++) cout << vowels[i];
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}