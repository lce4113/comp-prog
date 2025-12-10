// ––– CodeForces Global Round 14: Problem A –––

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
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int k = 0; k < n; k++) {
      cin >> arr[k];
    }

    if (n == 1 && arr[0] == x) {
      cout << "NO" << endl;
      continue;
    }

    sort(arr, arr + n);
    int sum = 0;
    for (int k = 0; k < n; k++) {
      if (sum == x) {
        int temp = arr[k - 1];
        arr[k - 1] = arr[k];
        arr[k] = temp;
        sum = -1;
        break;
      }
      sum += arr[k];
    }

    if (sum == x) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
    for (int k = 0; k < n; k++) {
      cout << arr[k] << ' ';
    }
    cout << endl;
  }
}
