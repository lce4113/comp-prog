// ––– Round #716: Problem A –––

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
    int n;
    cin >> n;
    int arr[n];
    for (int k = 0; k < n; k++) {
      cin >> arr[k];
    }

    bool b = false;
    for (int k = 0; k < n; k++) {
      int root = sqrt(arr[k]);
      if (root * root != arr[k]) {
        cout << "YES" << endl;
        b = true;
        break;
      }
    }
    if (b)
      continue;
    cout << "NO" << endl;
  }
}
