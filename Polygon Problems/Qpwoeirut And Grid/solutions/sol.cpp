// ––– "Qpwoeirut And Grid" - Fastest TLE Solution O(nlog(n)) –––

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

    ll pfs1[n + 1], pfs2[n + 1], half_sum = 0;
    pfs1[0] = 0, pfs2[0] = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pfs1[i + 1] = pfs1[i] + x;
      half_sum += x;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pfs2[i + 1] = pfs2[i] + x;
      half_sum += x;
    }
    half_sum /= 2;

    int ans = 0;
    for (int i = 0, k = n; i <= n && k >= 0;) {
      ll pfs_sum = pfs1[i] + pfs2[k];
      if (pfs_sum == half_sum) {
        i++, k--, ans++;
      } else if (pfs_sum > half_sum) {
        k--;
      } else {
        i++;
      }
    }

    cout << ans << '\n';
  }
}
