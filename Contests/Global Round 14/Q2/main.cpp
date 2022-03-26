// ––– CodeForces Global Round 14: Problem B –––

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

bool check(ll n)
{
  double s1 = sqrt((double)n / 4);
  bool b1 = s1 == floor(s1);
  double s2 = sqrt((double)n / 2);
  bool b2 = s2 == floor(s2);
  return b1 || b2;
}

int main()
{
  ll t;
  cin >> t;

  for (ll i = 0; i < t; i++) {
    ll n;
    cin >> n;
    if (n == 1 || n == 0) {
      cout << "NO" << endl;
      continue;
    }
    bool b = check(n);
    if (b) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
}
