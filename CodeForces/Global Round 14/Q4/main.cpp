// ––– CodeForces Global Round 14: Problem D –––

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
  for (int i = 0; i < t; i++) {
    int n, l, r;
    cin >> n >> l >> r;

    vi left, right;
    int elt;
    for (int k = 0; k < l; k++) {
      cin >> elt;
      left.pb(elt);
    }
    for (int k = 0; k < r; k++) {
      cin >> elt;
      right.pb(elt);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int d = abs(l - r);
    int mn = min(l, r);
    if (l > r) {
      for (int k = 0; k < r; k++) {
        if ()
      }
    } else {

    }

    if (l > r) {
      for (int k = 0; k < r - 1; k++) {
        if (right[k] == right[k + 1]) {
          left.pb();
        }
      }
    } else {
    }
    cout << d << endl;

    d += n / 2;
    cout << d << endl;
    set<int> lonely;
    for (int k = 0; k < n; k++) {
      if (lonely.count(arr[k]) == 1) {
        d--;
        lonely.erase(arr[k]);
      } else {
        lonely.insert(arr[k]);
      }
    }

    cout << d << endl
         << endl;
  }
}
