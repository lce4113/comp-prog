// ––– LIT 2021: Problem D –––

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

const int MAXN = 5 * 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int arr[MAXN];
vi dp;
dp.pb(1);

int tp(int n)
{
  if (dpa[n]) {
    return dpa[n];
  }

  ll ans = dp.back();
  for (int i = dp.size(); i <= n; i++) {
    ans *= 4;
    ans %= MOD;
    dpa.pb(ans);
  }
  return ans;
}

int f(int a, int b)
{
  ll ans;
  if (b - a == 2) {
    ans = (arr[a] == arr[b]) + 1;
    ans += (arr[a] == arr[b]);
  } else if ((b - a) % 2 == 0) {
    ans = (tp((b - a) / 2) - 1) / 3;
    ans += (arr[a] == arr[b]);
  } else {
    ans = 2 * (tp((b - a) / 2) - 1) / 3 + 1;
    ans -= (arr[a] == arr[b]);
  }
  ans %= MOD;
  return ans;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
  }

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      int a = i - 1, b = i;
      while (arr[b] == 0) {
        b++, i++;
      }
      ans *= f(a, b);
      ans %= MOD;
    }
  }

  cout << ans << '\n';
}
