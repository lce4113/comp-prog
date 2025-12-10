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

    int m;
    cin >> m;
    int arr[m];
    for (int j = 0; j < m; j++) {
      cin >> arr[j];
    }

    int num;
    if (arr[0] != arr[1] && arr[1] == arr[2]) {
      cout << 1 << endl;
      continue;
    } else {
      num = arr[0];
    }

    for (int j = 1; j < m; j++) {
      if (num != arr[j]) {
        cout << j + 1 << endl;
      }
    }
  }
}
