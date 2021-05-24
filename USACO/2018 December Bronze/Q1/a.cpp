// ––– USACO 2018 December Bronze: Problem A –––

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

  ifstream cin("mixmilk.in");
  ofstream cout("mixmilk.out");

  int c[3], m[3];
  for (int i = 0; i < 3; i++) {
    cin >> c[i] >> m[i];
  }



  for (int i = 0; i < 100; i++) {
    m[(i + 1) % 3] += m[i % 3];
    m[i % 3] = 0;
    if (m[(i + 1) % 3] > c[(i + 1) % 3]) {
      m[i % 3] = m[(i + 1) % 3] - c[(i + 1) % 3];
      m[(i + 1) % 3] = c[(i + 1) % 3];
    }
  }

  for (int i = 0; i < 3; i++) {
    cout << m[i] << '\n';
  }
}
