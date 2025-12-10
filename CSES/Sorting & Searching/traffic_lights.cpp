// CSES Sorting & Searching: Traffic Lights

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

set<int> lights;
multiset<int> dists;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int x, n;
  cin >> x >> n;

  lights.insert(0); lights.insert(x);
  dists.insert(x);
  for (int i = 0; i < n; i++) {
    int elt;
    cin >> elt;

    auto r = lights.upper_bound(elt);
    auto l = prev(r);
    dists.erase(dists.find(*r - *l));
    lights.insert(elt);
    dists.insert(*r - elt);
    dists.insert(elt - *l);

    cout << *dists.rbegin() << ' ';
  }
}
