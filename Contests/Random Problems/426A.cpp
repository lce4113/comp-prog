// ––– CodeForces Round #243: Problem A –––

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
  int n, s;
  cin >> n >> s;
  int m = -1, sum = 0;
  for (int i = 0; i < n; i++) {
    int elt;
    cin >> elt;

    if (elt > m)
      m = elt;
    sum += elt;
  }
  sum -= m;
  if (sum <= s)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
