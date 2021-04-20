// ––– Round #715: Problem A –––

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
    int n;
    cin >> n;

    vi even, odd;
    for (int k = 0; k < n; k++) {
      int elt;
      cin >> elt;
      if (elt % 2 == 0)
        even.pb(elt);
      else
        odd.pb(elt);
    }

    for (int k = 0; k < odd.size(); k++) {
      cout << odd[k] << ' ';
    }

    for (int k = 0; k < even.size(); k++) {
      cout << even[k] << ' ';
    }

    cout << endl;
  }
}
