// ––– CodeForces Contest 1227, Problem A: "Math Problem" –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int mn = 1e9, mx = 1;
    for (int i = 0; i < n; i++) {
      int x;
      int y;
      cin >> x >> y;
      mn = min(y, mn);
      mx = max(x, mx);
    }

    cout << max(0, mx - mn) << '\n';
  }
}
