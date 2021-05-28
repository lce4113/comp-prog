// ––– HEADER –––

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

  int n, q;
  cin >> n >> q;

  int pfs[n + 1];
  pfs[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pfs[i + 1] = pfs[i] + x;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    int a = pfs[r] - pfs[l - 1];
    int b = r - l + 1;
    int ans = pfs[n] - a + (b - a);
    cout << ans << '\n';
  }
}
