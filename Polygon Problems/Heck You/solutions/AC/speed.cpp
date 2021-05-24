// ––– "Heck you." - Main Solution File –––

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long pfs1[1000001], pfs2[1000001];
int c[100000], n, t, x, a, b, r;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> t;

  pfs1[0] = 0;
  pfs2[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    c[i] = x;
    pfs1[i + 1] = pfs1[i] + x;
    pfs2[i + 1] = pfs2[i] + (1 + i) * x;
  }

  while (t--) {
    cin >> a >> b >> r;
    cout << ((pfs2[b] - pfs2[a - 1]) * r + (pfs1[b] - pfs1[a - 1]) * (1 - r * a)) % MOD << '\n';
  }
}
