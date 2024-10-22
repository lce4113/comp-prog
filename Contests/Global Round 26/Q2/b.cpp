// CodeForces Global Round 26: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  string N = to_string(n);
  if (N[0] != '1') {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < N.size() - 1; i++) {
    if (N[i] == '0') {
      cout << "NO\n";
      return;
    }
  }
  if (N[N.size() - 1] == '9') {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
