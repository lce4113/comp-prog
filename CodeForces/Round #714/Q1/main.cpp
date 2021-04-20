// ––– Round #714: Problem A –––

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
    int r, p;
    cin >> r >> p;
    if (p >= (r + 1) / 2) {
      cout << -1 << endl;
      continue;
    }
    int arr[r - 1 + 1];
    for (int j = 0; j < r - 1 + 1; j++) {
      arr[j] = 1 + j;
    }
    for (int j = 0; j < p; j++) {
      int temp = arr[2 * j + 1];
      arr[2 * j + 1] = arr[2 * j + 2];
      arr[2 * j + 2] = temp;
    }
    for (int j = 0; j < r; j++) {
      cout << arr[j] << ' ';
    }
    cout << endl;
  }
}
