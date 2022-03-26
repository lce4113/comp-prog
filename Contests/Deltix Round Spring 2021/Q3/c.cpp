// ––– CodeForces Deltix Round Spring 2021: Problem C –––

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

    vi ans[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      vi a;
      if (i != 0) {
        if (x == 1) {
          for (int k : ans[i - 1]) {
            a.pb(k);
          }
        } else {
          for (int k = ans[i - 1].size() - 1;;k--) {
            if (x == ans[i - 1][k] + 1) {
              for (int l = 0; l < k; l++) {
                a.pb(ans[i - 1][l]);
              }
              break;
            }
          }
        }
      }
      a.pb(x);

      ans[i] = a;
    }

    for (vi v : ans) {
      for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << '.';
      }
      cout << v[v.size() - 1] << '\n';
    }
  }
}
