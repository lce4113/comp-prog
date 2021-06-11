// ––– CodeForces Round #725: Problem C –––

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
    int n, l, r;
    cin >> n >> l >> r;

    int arr1[n];
    pi arr2[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr1[i] = x;
      arr2[i] = mp(l - x, r - x);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a = arr1[i];
      for (int k = i + 1; k < n; k++) {
        if (arr2[k].f <= a && a <= arr2[k].s) {
          ans++;
        }
      }
    }

    cout << ans << '\n';
  }
}
