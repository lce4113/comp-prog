// ––– Educational Round 108: Problem A –––

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
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int r, b, d;
    cin >> r >> b >> d;
    if (ceil((double)max(r, b) / min(r, b)) - 1 > d) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
}
