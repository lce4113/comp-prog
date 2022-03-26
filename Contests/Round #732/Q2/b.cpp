// ––– CodeForces Round #732: Problem B –––

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
    int n, m;
    cin >> n >> m;

    int a[m][26];
    for (int i = 0; i < m; i++) {
      for (int k = 0; k < 26; k++) {
        a[i][k] = 0;
      }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
      str x;
      cin >> x;
      for (int k = 0; k < m; k++) {
        a[k][x[k] - 'a']++;
      }
    }

    str ans = "";
    for (int i = 0; i < m; i++) {
      for (int k = 0; k < 26; k++) {
        if (a[i][k] % 2) {
          char l = 'a' + k;
          cout << l;
          break;
        }
      }
    }
    cout << '\n';
  }
}
