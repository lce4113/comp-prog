// ––– CodeForces Be Positive: Problem A –––

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

  int n;
  cin >> n;

  int p = 0, z = 0, neg = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      p++;
    } else if (x == 0) {
      z++;
    } else {
      neg++;
    }
  }

  if (p >= (n + 1) / 2) {
    cout << 1 << '\n';
  } else if (neg >= (n + 1) / 2) {
    cout << -1 << '\n';
  } else {
    cout << 0 << '\n';
  }
}
