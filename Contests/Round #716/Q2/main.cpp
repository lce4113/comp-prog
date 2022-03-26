// ––– Round #716: Problem B –––

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

#define MOD 1000000007

ll exp(ll a, ll b)
{
  ll e = 1;
  for (ll i = 0; i < b; i++) {
    e *= a;
    e = e % MOD;
  }
  return e;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll n, m;
    cin >> n >> m;
    ll p = exp(n, m);
    cout << p << endl;
  }
}
