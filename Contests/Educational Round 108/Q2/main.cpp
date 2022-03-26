// ––– Educational Round 108: Problem B –––

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
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m - 1 == k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
