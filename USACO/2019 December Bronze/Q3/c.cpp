// ––– USACO 2019 December Bronze: Problem C –––

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

str cows[8] = {
  "Beatrice",
  "Belinda",
  "Bella",
  "Bessie",
  "Betsy",
  "Blue",
  "Buttercup",
  "Sue",
};
int n;
pair<str, str> arr[7];

bool check() {
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 8; k++) {
      if (cows[k] == arr[i].f) {
        if (
            (k != 0 && cows[k - 1] != arr[i].s) &&
            (k != 8 && cows[k + 1] != arr[i].s)
           ) return false;
      }
      if (cows[k] == arr[i].s) {
        if (
            (k != 0 && cows[k - 1] != arr[i].f) &&
            (k != 8 && cows[k + 1] != arr[i].f)
           ) return false;
      }
    }
  }
  return true;
}

int main()
{
  ifstream cin("lineup.in");
  ofstream cout("lineup.out");

  cin >> n;

  for (int i = 0; i < n; i++) {
    str a, x1, x2, x3, x4, b;
    cin >> a >> x1 >> x2 >> x3 >> x4 >> b;
    arr[i] = mp(a, b);
  }

  do {
    if (check()) break;
  } while(next_permutation(cows, cows + 8));

  for (int i = 0; i < 8; i++) {
    cout << cows[i] << '\n';
  }
}
