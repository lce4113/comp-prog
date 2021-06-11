// ––– CodeForces Round #479: Problem D –––

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

const int MAXN = 100;

set<int> a;
int b[MAXN];

int[] e(int b[])
{
  
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.insert(x);
  }

  for (int x : e(b)) {
    cout << x << ' ';
  }
}
