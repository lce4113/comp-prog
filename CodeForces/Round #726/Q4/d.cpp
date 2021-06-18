// ––– CodeForces Round #726: Problem D –––

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

vi pf(int n)
{
  vi b;
  while (n % 2 == 0) {
    b.pb(2);
    n = n / 2;
  }

  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      b.pb(i);
      n = n / i;
    }
  }

  if (n > 2) {
    b.pb(n);
  }
  return b;
}

bool isp(vi b)
{
  int m = 0;
  for (auto& x : b) {
    if (x != 1) {
      m++;
    }
  }
  return (m <= 1);
}

bool a(vi b, int c)
{
  if (c != -1) {
    b[c]--;
  }
  if (isp(b)) {
    return true;
  }
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == 1)
      continue;
    a(b, i);
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vi b = pf(n);

    if (a(b, -1)) {
      cout << "Bob" << '\n';
    } else {
      cout << "Alice" << '\n';
    }
  }
}
