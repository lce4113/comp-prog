// ––– CodeForces Boboniu Likes to Color Balls: Problem A –––

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
    int r, g, b, w;
    cin >> r >> g >> b >> w;

    int o = 0;
    bool sw = true;
    int sm = w;
    for (int x : { r, g, b }) {
      if (x % 2 == 1)
        o++;
      if (x == 0)
        sw = false;
      sm += x;
    }

    if (sm % 2 == 0) {
      if (w % 2 == 0 && o == 0) {
        cout << "YES" << '\n';
      } else if (w % 2 == 1 && o == 3 && sw) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      if (w % 2 == 0 && o == 1) {
        cout << "YES" << '\n';
      } else if (w % 2 == 0 && o == 3 && sw) {
        cout << "YES" << '\n';
      } else if (w % 2 == 1 && o == 0) {
        cout << "YES" << '\n';
      } else if (w % 2 == 1 && o == 2 && sw) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
}
