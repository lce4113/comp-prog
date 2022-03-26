// ––– CodeForces Contest 1060, Problem B: "Maximum Sum of Digits" –––

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

ll S(ll n)
{
  ll sm = 0;
  while (n) {
    sm += n % 10;
    n /= 10;
  }
  return sm;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  ll N = n, l = 1;
  for (; N; l *= 10) {
    N /= 10;
  }
  l /= 10;

  ll a = n - (n % l) - 1;
  ll b = n - a;

  cout << S(a) + S(b) << '\n';
}
