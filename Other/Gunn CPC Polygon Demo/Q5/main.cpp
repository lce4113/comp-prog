// ––– CodeForces Gunn CPC Polygon Demo: Problem E –––

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

const int MOD = 1e9 + 7;

int pow2(int k, int n)
{
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = (ans * k) % MOD;
  }
  return ans;
}

int solve(map<int, int> m1, map<int, int> m2, int k)
{
  if (k == 1)
    return true;
  int a = 1, b = 1;
  while (true) {
    if (m1[a]) {
      m2.erase(b);
      m1.erase(a);
      b = a;
      a = m1[a];
    } else if (m2[a]) {
      m1.erase(b);
      m2.erase(a);
      b = a;
      a = m2[a];
    } else {
      return false;
    }
    if (a == k)
      return true;
    if (a == 1)
      return false;
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    n--;
    map<int, int> m1, m2;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      m1[a] = b;
      m2[b] = a;
    }
    if (solve(m1, m2, k)) {
      cout << "YES" << endl;
      cout << pow2(k, 100) << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
