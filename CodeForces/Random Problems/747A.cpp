// ––– CodeForces "Display Size": Problem A –––

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

  int a = 1, b = n;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0 && (n / i - i) < (b - a)) {
      a = i;
      b = n / i;
    }
  }
  cout << a << ' ' << b << '\n';
}
