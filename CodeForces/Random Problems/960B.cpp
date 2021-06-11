// ––– CodeForces Contest 960, Problem B: "Minimize the error" –––

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

  int n, k1, k2;
  cin >> n >> k1 >> k2;

  ll a[n];
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a[i] = x;
  }
  ll b[n];
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    b[i] = x;
  }

  priority_queue<ll> p;
  for (int i = 0; i < n; i++) {
    p.push(abs(a[i] - b[i]));
  }
  for (int i = 0; i < k1 + k2; i++) {
    ll a = abs(p.top() - 1);
    p.pop();
    p.push(a);
  }
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    sm += p.top() * p.top();
    p.pop();
  }
  cout << sm << '\n';
}
