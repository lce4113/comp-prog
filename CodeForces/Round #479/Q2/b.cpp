// ––– CodeForces Round #479: Problem B –––

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
  str S;
  cin >> S;

  map<str, int> m;
  for (int i = 0; i < n - 1; i++) {
    if (m[S.substr(i, 2)]) {
      m[S.substr(i, 2)]++;
    } else {
      m[S.substr(i, 2)] = 1;
    }
  }

  str a;
  int b = -1;
  for (pair<str, int> x : m) {
    if (b < x.s) {
      a = x.f;
      b = x.s;
    }
  }

  cout << a << '\n';
}
