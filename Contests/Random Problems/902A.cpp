// ––– CodeForces Contest 902, Problem A: "Visiting a Friend" –––

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

  int n, m;
  cin >> n >> m;

  int s = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= s) {
      s = max(s, y);
    }
  }

  if (s >= m) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
