// ––– CodeForces Round #629: Problem F –––

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

#define eq(a, b, eps) (abs(a - b) < eps)

#define init(arr)                               \
  {                                             \
    int arrSize = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < arrSize; i++) {         \
      arr[i] = 0;                               \
    }                                           \
  }

// ––– CODE –––

#define int ll

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  mp a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }

  vi b, c;
  for (auto& x : a) {
    b.pb(x.f);
    c.pb(x.s);
    if (x.s >= k) {
      cout << 0 << '\n';
      return 0;
    }
  }

  n = b.size();

  int sm1 = 0, sm2 = 0, sm3 = 0;
  pl pfs1[n];
  for (int i = 0; i < n - 1; i++) {
    sm1 += c[i];
    sm3 += c[i] * (b[i + 1] - b[i]);
    sm2 += sm3;
    pfs1[i + 1] = { sm1, sm2 };
  }

  sm1 = 0, sm2 = 0, sm3 = 0;
  pl pfs2[n];
  for (int i = 0; i < n - 1; i++) {
    sm1 += c[n - i - 1];
    sm3 += c[n - i - 1] * (b[n - i - 1] - b[n - i - 2]);
    sm2 += sm3;
    pfs2[n - i - 2] = { sm1, sm2 };
  }

  int ans = LLONG_MAX;

  pl e = pfs2[0];
  if (e.f + c[0] >= k) {
    int x = e.s;
    x -= (b[1] - b[0]) * (e.f + c[0] - k);
    ans = min(ans, x);
  }

  for (int i = 1; i < n - 1; i++) {
    pl d = pfs1[i];
    pl e = pfs2[i];

    if (d.f + e.f + c[i] >= k) {
      int x = d.s + e.s;
      if (b[i] - b[i - 1] > b[i + 1] - b[i]) {
        if (e.f + c[i] >= k) {
          x -= d.s;
          x -= (b[i + 1] - b[i]) * (e.f + c[i] - k);
        } else if (d.f + c[i] >= k) {
          x -= e.s;
          x -= (b[i] - b[i - 1]) * (d.f + c[i] - k);
        } else {
          x -= (b[i] - b[i - 1]) * (d.f + e.f + c[i] - k);
        }
      } else {
        if (d.f + c[i] >= k) {
          x -= e.s;
          x -= (b[i] - b[i - 1]) * (d.f + c[i] - k);
        } else if (e.f + c[i] >= k) {
          x -= d.s;
          x -= (b[i + 1] - b[i]) * (e.f + c[i] - k);
        } else {
          x -= (b[i + 1] - b[i]) * (d.f + e.f + c[i] - k);
        }
      }
      ans = min(ans, x);
    }
  }

  pl D = pfs1[n - 1];
  if (D.f + c[n - 1] >= k) {
    int x = D.s;
    x -= (b[n - 1] - b[n - 2]) * (D.f + c[n - 1] - k);
    ans = min(ans, x);
  }

  cout << ans << '\n';
}
