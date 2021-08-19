// ––– CodeForces Contest 378, Problem A: "Playing with Dice" –––

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
using vc = vector<char>;
using vs = vector<str>;
using vl = vector<ll>;
using mp = map<int, int>;
using mset = multiset<int>;
using pq = priority_queue<int>;
using rpq = priority_queue<int, vi, greater<int>>;
using dq = deque<int>;

// Other Shortcuts

#define f first
#define s second
#define pb push_back
#define pf push_front

// Functions

#define init(arr)                               \
  {                                             \
    int arrSize = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < arrSize; i++) {         \
      arr[i] = 0;                               \
    }                                           \
  }

#define ins(map, elt)     \
  {                       \
    if (map.count(elt)) { \
      map[elt]++;         \
    } else {              \
      map[elt] = 1;       \
    }                     \
  }

// ––– CODE –––

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int a, b;
  cin >> a >> b;

  int A, D, B;
  if (a == b) {
    D = 6;
  } else if (a % 2 == b % 2) {
    D = 1;
  } else {
    D = 0;
  }

  if (a == b) {
    A = 0, B = 0;
  } else if (a > b) {
    B = (a + b) / 2 - D;
    A = 6 - B - D;
  } else {
    A = (a + b) / 2 - D;
    B = 6 - A - D;
  }

  cout << A << ' ' << D << ' ' << B << '\n';
}
