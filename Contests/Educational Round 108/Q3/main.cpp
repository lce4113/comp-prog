// ––– Educational Round 108: Problem C –––

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

bool cmp(int b, int a)
{
  return b > a;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vi u2[n];
    int u[n], mu = 0;
    for (int k = 0; k < n; k++) {
      int elt;
      cin >> elt;
      u[k] = elt;
      if (elt > mu)
        mu = elt;
      vi vec;
      u2[elt - 1] = vec;
    }
    for (int k = 0; k < n; k++) {
      int elt;
      cin >> elt;
      u2[u[k] - 1].pb(elt);
    }

    ll ans[n];
    memset(ans, 0, sizeof ans);

    ll pfs[n];
    for (int l = 0; l < mu; l++) {
      sort(u2[l].begin(), u2[l].end(), cmp);
      pfs[0] = 0;
      for (int p = 0; p < u2[l].size(); p++) {
        pfs[p + 1] = pfs[p] + u2[l][p];
      }
      for (int p = 0; p < n; p++) {
        cout << pfs[p] << ' ';
      }
      cout << endl;
      for (int k = 0; k < n; k++) {
        int len = u2[l].size();
        int sumpos = len - (len % (k + 1));
        ans[k] += pfs[sumpos];
      }
    }

    for (int k = 0; k < n; k++) {
      cout << ans[k] << ' ';
    }
    cout << endl;
  }
}
