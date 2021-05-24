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

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, t;
  cin >> n >> t;
  cout << t << '\n';

  int c[n];
  ll pfs1[n + 1], pfs2[n + 1];
  pfs1[0] = 0;
  pfs2[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    pfs1[i + 1] = pfs1[i] + c[i];
    pfs2[i + 1] = pfs2[i] + (1 + i) * c[i];
  }

  while (t--) {
    int a, b, r;
    cin >> a >> b >> r;

    ll hugs1 = pfs1[b] - pfs1[a - 1];
    ll hugs2 = pfs2[b] - pfs2[a - 1];
    ll scaledHugs = hugs2 * r - hugs1 * (r - 1);
    ll subRect = hugs1 * (a - 1) * r;
    ll ans = (scaledHugs - subRect) % MOD;

    cout << pfs1[1] << '\n';
  }
}
