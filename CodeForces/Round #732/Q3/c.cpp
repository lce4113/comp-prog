// ––– CodeForces Round #732: Problem C –––

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

    int a[n];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
    }

    int c[100001][2];
    for (auto& x : c) {
      for (auto& y : x) {
        y = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      c[a[i]][i % 2]++;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
      c[a[i]][i % 2]--;
    }

    for (auto& x : c) {
      for (auto& y : x) {
        if (y) {
          goto done;
        }
      }
    }

    cout << "YES" << '\n';
    continue;
  done:
    cout << "NO" << '\n';
  }
}
