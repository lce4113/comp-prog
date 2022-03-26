// ––– Round #714: Problem F –––

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
  int n;
  cin >> n;

  ll a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  ll ans = 0;
  for (int k = 0; k < n; k++) {
    ans += abs(a[k] - b[k]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (a[i] > b[i] && a[j] > b[j])
        continue;
      if (a[i] < b[i] && a[j] < b[j])
        continue;
      if (a[i] == b[i] || a[j] == b[j])
        continue;

      ll a2[n], b2[n];
      for (int k = 0; k < n; k++) {
        a2[k] = a[k];
        b2[k] = b[k];
      }

      ll temp = a2[i];
      a2[i] = a2[j];
      a2[j] = temp;

      ll total = 0;
      for (int k = 0; k < n; k++) {
        total += abs(a2[k] - b2[k]);
      }

      if (total < ans)
        ans = total;
    }
  }
  cout << ans;
}
