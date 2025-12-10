// CSES Introductory Problems: Repetitions

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    string a;
    cin >> a;
    int n = a.size();
    int ans = -1;
    for (int i = 0; i < n;) {
        int start = i;
        while (i < n && a[start] == a[i]) i++;
        ans = max(ans, i - start);
    }
    cout << ans << '\n';
}