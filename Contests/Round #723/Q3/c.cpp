// ––– CodeForces Round #723: Problem C –––

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
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll S = 0;

  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    S += x;
    pq.push(x);

    while (S < 0) {
      S -= pq.top();
      pq.pop();
    }
  }

  cout << pq.size();
}
