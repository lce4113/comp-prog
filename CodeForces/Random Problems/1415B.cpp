// ––– CodeForces Contest 1415, Problem B: "Repainting Street" –––

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
    int n, l;
    cin >> n >> l;

    int arr[n], m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = x;
      m = max(m, x);
    }

    int ans = 1e5 + 5;
    for (int i = 1; i <= m; i++) {
      int a = 0;
      for (int k = 0; k < n; k++) {
        if (arr[k] != i) {
          a++;
          k += l - 1;
        }
      }
      ans = min(ans, a);
    }

    cout << ans << '\n';
  }
}
