// ––– CodeForces Contest 82, Problem A: "Double Cola" –––

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

  int a = 0, i = 0;
  for (; a <= n; i++) {
    a += 5 * pow(2, i);
  }
  i--;
  a -= 5 * pow(2, i);
  double b = n - a;

  int c = ceil(b / pow(2, i));
  switch (c) {
  case 1:
    cout << "Sheldon" << '\n';
    break;
  case 2:
    cout << "Leonard" << '\n';
    break;
  case 3:
    cout << "Penny" << '\n';
    break;
  case 4:
    cout << "Rajesh" << '\n';
    break;
  case 5:
    cout << "Howard" << '\n';
    break;
  case 0:
    cout << "Howard" << '\n';
    break;
  }
}
