// ––– CodeForces Competitive Programmer: Problem A –––

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

vi digits(int n)
{
  vi d;
  while (n > 0) {
    d.pb(n % 10);
    n /= 10;
  }
  return d;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    str n;
    cin >> n;

    bool b = false, b2 = false;
    int sm = 0;
    for (int i = 0; i < n.length(); i++) {
      int x = stoi(n.substr(i, 1));
      sm += x;
      if (!b && x == 0)
        b = true;
      else if (x == 0 || x == 2 || x == 4 || x == 6 || x == 8)
        b2 = true;
    }
    if (!b || !b2) {
      cout << "cyan" << '\n';
      continue;
    }
    if (sm % 3 != 0) {
      cout << "cyan" << '\n';
      continue;
    }
    cout << "red" << '\n';
  }
}
