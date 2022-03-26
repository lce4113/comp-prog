// ––– CodeForces Three Pairwise Maximums: Problem A –––

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

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
      cout << abs(y1 - y2) << '\n';
    else if (y1 == y2)
      cout << abs(x1 - x2) << '\n';
    else
      cout << (abs(x1 - x2) + abs(y1 - y2) + 2) << '\n';
  }
}
