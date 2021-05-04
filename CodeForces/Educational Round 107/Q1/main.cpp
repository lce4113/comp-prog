// ––– Educational Round #107: Problem A –––

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
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int u1 = 0, d1 = 0, u2 = 0, d2 = 0;
    for (int j = 0; j < n; j++) {
      int r;
      cin >> r;

      if (r == 1) {
        u1++;
      } else if (r == 2) {
        d2++;
      } else {
        u1++;
      }
    }
    cout << u1 + u2 << endl;
  }
}
