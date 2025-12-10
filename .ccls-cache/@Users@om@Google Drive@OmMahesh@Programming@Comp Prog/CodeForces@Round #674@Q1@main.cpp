// ––– CodeForces Round #674: Problem A –––

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
    int n, x;
    cin >> n >> x;
    n -= 2;

    int ans = 1;
    while (n > 0) {
      n -= x;
      ans++;
    }

    cout << ans << endl;
  }
}
