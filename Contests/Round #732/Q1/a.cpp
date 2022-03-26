// ––– CodeForces Round #732: Problem A –––

#include <bits/stdc++.h>
using namespace std;

// Data Type Shortcuts

using str = string;
using ll = long long;
using db = double;
using ld = long double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using mset = multiset<int>;
using pq = priority_queue<int>;
using rpq = priority_queue<int, vi, greater<int>>;
using dq = deque<int>;

// Other Shortcuts

#define f first
#define s second
#define mp make_pair
#define pb push_back

// Functions

#define ins(map, el) \
  {                  \
    if (map[el]) {   \
      map[el]++;     \
    } else {         \
      map[el] = 1;   \
    }                \
  }

// ––– CODE –––

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n], sm = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      sm += x;
    }

    int b[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[i] = x;
      sm -= x;
    }

    if (sm != 0) {
      cout << -1 << '\n';
      continue;
    }

    vi add, sub;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < abs(b[i] - a[i]); k++) {
        if (b[i] > a[i]) {
          sub.pb(i + 1);
        } else {
          add.pb(i + 1);
        }
      }
    }

    vector<pi> ans;
    for (int i = 0; i < add.size(); i++) {
      ans.pb({ add[i], sub[i] });
    }

    cout << ans.size() << '\n';
    for (auto& x : ans) {
      cout << x.f << ' ' << x.s << '\n';
    }
    cout << '\n';
  }
}
