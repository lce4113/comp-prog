// ––– CodeForces "Gifts Fixing": Problem B –––

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

    ll m1 = 1e9, arr1[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < m1)
        m1 = x;
      arr1[i] = x;
    }

    ll m2 = 1e9, arr2[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < m2)
        m2 = x;
      arr2[i] = x;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += max(arr1[i] - m1, arr2[i] - m2);
    }

    cout << ans << '\n';
  }
}
