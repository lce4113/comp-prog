// ––– "Heck you." - Main Solution File –––

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

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;

ll pfs1[MAXN], pfs2[MAXN];
int n, t, x, a, b, r;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> t;

  pfs1[0] = 0;
  pfs2[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    pfs1[i + 1] = pfs1[i] + x;
    pfs2[i + 1] = pfs2[i] + (1 + i) * x;
  }

  while (t--) {
    cin >> a >> b >> r;
    cout << ((pfs2[b] - pfs2[a - 1]) * r + (pfs1[b] - pfs1[a - 1]) * (1 - r * a)) % MOD << '\n';
  }
}
