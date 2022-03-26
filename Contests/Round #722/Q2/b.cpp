// ––– CodeForces Round #722: Problem B –––

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

    int a[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
    }
    sort(a, a + n);

    int dist = 1e9 + 5;
    for (int i = 1; a[i] <= 0 && i < n; i++) {
      if (a[i] - a[i - 1] < dist)
        dist = a[i] - a[i - 1];
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] <= dist && a[i - 1] <= 0) {
        ans = i + 1;
      }
    }
    cout << ans << "\n";
  }
}
