// ––– "Heck you." - TLE Solution File –––

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

#define MAXR 100
const int MOD = 1e9 + 7;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, t;
  cin >> n >> t;

  int c[n];
  ll pfs1[n + 1], pfs2[MAXR + 1][n + 1];
  pfs1[0] = 0;
  for (int r = 1; r <= MAXR; r++) {
    pfs2[r][0] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    pfs1[i + 1] = pfs1[i] + c[i];
    for (int r = 1; r <= MAXR; r++) {
      pfs2[r][i + 1] = pfs2[r][i] + (1 + i * r) * c[i];
    }
  }

  while (t--) {
    int a, b, r;
    cin >> a >> b >> r;

    cout << ((pfs2[r][b] - pfs2[r][a - 1]) - (pfs1[b] - pfs1[a - 1]) * (a - 1) * r) % MOD << '\n';
  }
}
