// ––– CodeSprint Beginner 2021: Problem D –––

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

  int p, M;
  cin >> p >> M;

  int m = M;

  int a = 0;
  while (m >= 0) {
    a++;
    m -= 4 * a;
  }
  m += 4 * a;

  if (m == 0) {
    cout << "Touch" << '\n';
  } else if (m <= a) {
    cout << "Efficiency" << '\n';
  } else if (m <= 2 * a) {
    cout << "Unbreaking" << '\n';
  } else if (m % 2 == 1) {
    cout << "Silk" << '\n';
  } else {
    cout << "Touch" << '\n';
  }

  if (m == 0)
    m = a;
  int md = ((M + (a - m) - 1) % p) + 1;

  cout << md;
}
