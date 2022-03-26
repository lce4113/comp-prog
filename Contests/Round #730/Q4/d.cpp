// ––– CodeForces Round #730: Problem D –––

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

bool ask(int n)
{
  cout << n << '\n';
  cout.flush();
  int x;
  cin >> x;
  return x;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k, x = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
      int y = x ^ i;
      if (ask(y)) {
        break;
      }
      x ^= y;
    }
  }
}
