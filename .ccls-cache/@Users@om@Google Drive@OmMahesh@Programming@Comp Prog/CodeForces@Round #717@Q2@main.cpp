// ––– Round #717: Problem B –––

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

#define MAX 30

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {

    int n;
    cin >> n;
    int arr[MAX];
    for (int k = 0; k < MAX; k++)
      arr[k] = 0;

    for (int k = 0; k < n; k++) {
      ll elt;
      cin >> elt;
      for (int l = 0; elt > 0; l++) {
        if (elt & 1)
          arr[l]++;
        elt = elt >> 1;
      }
    }

    for (int k = 0; k < MAX; k++) {
      cout << arr[k] << ' ';
    }
    cout << endl;

    bool b = false;
    for (int k = 0; k < MAX; k++) {
      if (arr[k] % 2 == 1) {
        cout << "NO" << endl;
        b = true;
        break;
      }
    }
    if (b)
      continue;

    cout << "YES" << endl;
  }
}
