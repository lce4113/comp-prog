// CodeForces Educational Round 146: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    n -= k;
    if (n >= 0 && n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}
