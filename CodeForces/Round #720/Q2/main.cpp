// ––– CodeForces Round #720: Problem B –––

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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    vi bad;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i != 0) {
        int one = arr[i - 1];
        int two = arr[i];
        int g = gcd(one, two);
        if (g != 1) {
          bad.pb(i - 1);
        }
      }
    }
    if (bad.size() == 0) {
      cout << 0 << endl;
      continue;
    }

    vector<pair<pi, pi>> ops;
    for (int i = 0; i < bad.size(); i++) {
      int one = arr[bad[i]];
      int two = arr[bad[i + 1]];
      int g = gcd(one, two);
      if (arr[bad[i]]) {
        arr[bad[i]] = two;
        arr[bad[i + 1]] = one;
        ops.pb(mp(mp(bad[i], bad[j]), mp(bad[i])));
        ops.erase();
      } else {
        int b2 = (bad[i] == 0 ? n - 1 : bad[i] - 1);
        arr[bad[i]] = two;
        arr[b2] = one;
        ops.pb(mp(mp(bad[i], bad[j]), mp(bad[i])));
      }
    }
    cout << endl;
  }
}
