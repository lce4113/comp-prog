// ––– CSES Chessboard and Queens –––

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

set<pi> reserved;

bool check(int x[], int y[]) {
  set<int> diags1;
  set<int> diags2;
  for (int i = 0; i < 8; i++) {
    /* if (reserved.count(mp(x[i], y[i]))) return false; */
    int diag1 = x[i] + y[i];
    int diag2 = x[i] - y[i];
    /* if (diags1.count(diag1)) return false; */
    /* if (diags2.count(diag2)) return false; */
    diags1.insert(diag1);
    diags2.insert(diag2);
  }
  return true;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      char x;
      cin >> x;
      if (x == '*') reserved.insert(mp(i, k));
    }
  }

  int x[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int y[8] = {0, 1, 2, 3, 4, 5, 6, 7};

  int ans = 0;
  do {
    do {
      if (check(x, y)) ans++;
    } while(next_permutation(y, y + 8));
  } while(next_permutation(x, x + 8));

  cout << ans << '\n';
}
