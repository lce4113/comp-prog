// ––– CodeForces Educational Round 111: Problem D –––

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

const ll MOD = 1e9 + 7;
const ll MAXN = 2 * 1e5 + 5;

ll fact[MAXN], inv[MAXN];

ll binexp(ll a, ll b)
{
  if (b == 0)
    return 1ll;
  if (b == 1)
    return a % MOD;
  if (b % 2)
    return (a * binexp(a, b - 1)) % MOD;
  return binexp((a * a) % MOD, b / 2);
}
ll ginv(ll a) { return binexp(a, MOD - 2); }
ll choose(ll a, ll b)
{
  if (a < 0 || b < 0 || a - b < 0)
    return 0;
  ll res = (fact[a] * inv[b]) % MOD;
  res = (res * inv[a - b]) % MOD;
  return res;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = ((ll)i * fact[i - 1]) % MOD;
    inv[i] = ginv(fact[i]);
  }

  ll t;
  cin >> t;
  while (t--) {
    ll n, l, r;
    cin >> n >> l >> r;

    l -= n, r--;

    if (l >= 0) {
      cout << 0 << '\n';
      continue;
    }

    if (r > abs(l)) {
      ll tmp = -l;
      l = -r;
      r = tmp;
    }

    ll ans = 0;
    for (ll i = 1; i <= abs(l); i++) {
      ll a = min(i, n);
      ll b = min(r - abs(l + i - 1) + 1, n);

      if (a + b == n) {
        if (abs(a - b) == 1 || abs(a - b) == 0) {
          ans++;
        }
        continue;
      } else if (a + b < n) {
        continue;
      }

      ll c = a + b - n;
      ll d = a - c;
      ll e = b - c;

      ll x = abs(d - e);

      if (n % 2) {
        ans += choose(c, (c + (x + 1)) / 2);
        ans += choose(c, (c + (x - 1)) / 2);
      } else {
        ans += choose(c, (c + x) / 2);
      }
      ans %= MOD;
    }

    cout << ans << '\n';
  }
}
